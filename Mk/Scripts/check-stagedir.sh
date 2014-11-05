#!/bin/sh
# ports/Mk/Scripts/check-stagedir.sh - called from ports/Mk/bsd.stage.mk
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#
# This script serves 2 purposes:
# 1. Generate a plist
# 2. Test a plist for issues:
#  a. Files in STAGEDIR that are missing from plist
#  b. Files in plist missing from STAGEDIR
#  c. Files in plist which are owned by dependencies/MTREEs

set -e
export LC_ALL=C

#### EXPAND TMPPLIST TO ABSOLUTE PATHS, SPLITTING FILES AND DIRS TO
#    Use file descriptors 1 and 3 so that the while loop can write
#    files to the pipe and dirs to a separate file.
parse_plist() {
	echo "===> Parsing plist"
	cwd=${PREFIX}
	cwd_save=
	commented_cwd=
	while read line; do
		# Handle deactivated OPTIONS. Treat "@comment file" as being in
		# the plist so it does not show up as an orphan. PLIST_SUB uses
		# a @comment to deactive files. XXX: It would be better to
		# make all ports use @ignore instead of @comment.
		comment=
		if [ ${makeplist} -eq 0 -a -z "${line%%@comment *}" ]; then
			line="${line##*@comment }"
			# Remove @comment so it can be parsed as a file,
			# but later prepend it again to create a list of
			# all files commented and uncommented.
			comment="@comment "
			# Only consider comment @cwd for commented lines
			if [ -n "${commented_cwd}" ]; then
				[ -z "${cwd_save}" ] && cwd_save=${cwd}
				cwd=${commented_cwd}
			fi
		else
			# On first uncommented line, forget about commented
			# @cwd
			if [ -n "${cwd_save}" ]; then
				cwd=${cwd_save}
				cwd_save=
				commented_cwd=
			fi
		fi

		# Strip (owner,group,perm) from keywords
		line="$(printf %s "$line" \
		    | sed -Ee 's/^@\([^)]*\)[[:space:]]+//' \
			-e 's/^(@[[:alpha:]]+)\([^)]*\)[[:space:]]+/\1 /')"
		case $line in
		@dir*|'@unexec rmdir'*|'@unexec /bin/rmdir'*)
			line="$(printf %s "$line" \
			    | sed -Ee 's/\|\|.*//;s|[[:space:]]+[0-9]*[[:space:]]*>[&]?[[:space:]]*[^[:space:]]+||g' \
			        -e "/^@unexec[[:space:]]+(\/bin\/)?rmdir( -p)?/s|([^%])%D([^%])|\1${cwd}\2|g" \
			        -e '/^@unexec[[:space:]]+(\/bin\/)?rmdir( -p)?/s|"(.*)"[[:space:]]*|\1|g' \
			        -e 's/@unexec[[:space:]]+(\/bin\/)?rmdir( -p)?[[:space:]]+//' \
				-e 's/@dir(rm|rmtry)?[[:space:]]+//' \
				-e 's/[[:space:]]+$//')"
			case "$line" in
			/*) echo >&3 "${comment}${line%/}" ;;
			*)  echo >&3 "${comment}${cwd}/${line%/}" ;;
			esac
		;;
		# Handle [file] Keywords
		@info\ *|@shell\ *)
			set -- $line
			shift
			case "$@" in
			/*) echo "${comment}$@" ;;
			*) echo "${comment}${cwd}/$@" ;;
			esac
		;;
		@sample\ *)
			set -- $line
			shift
			# Ignore the actual file if it is in stagedir
			case "$@" in
			/*)
			echo "@comment ${@%.sample}"
			echo "${comment}$@"
			;;
			*)
			echo "@comment ${cwd}/${@%.sample}"
			echo "${comment}${cwd}/$@"
			;;
			esac
		;;
		# Handle [dir] Keywords
		@fc\ *|@fcfontsdir\ *|@fontsdir\ *)
			set -- $line
			shift
			case "$@" in
			/*)
			echo >&3 "${comment}$@"
			;;
			*)
			echo >&3 "${comment}${cwd}/$@"
			;;
			esac
		;;

		# order matters here - we must check @cwd first because
		# otherwise the @cwd* would also match it first, shadowing the
		# @cwd) line.
		@cwd|@cd)
			# Don't actually reset cwd for commented @cwd
			if [ -n "${comment}" ]; then
				commented_cwd=${PREFIX}
			else
				cwd=${PREFIX}
			fi
			;;
		@cwd*|@cd*)
			set -- $line
			newcwd=$2
			# Don't set cwd=/ as it causes // in plist and
			# won't match later.
			[ "${newcwd}" = "/" ] && newcwd=
			# Don't actually reset cwd for commented @cwd
			if [ -n "${comment}" ]; then
				commented_cwd=${newcwd}
			else
				cwd=${newcwd}
			fi
			unset newcwd
			;;
		@*) ;;
		/*) echo "${comment}${line}" ;;
		*)  echo "${comment}${cwd}/${line}" ;;
		esac
	done < ${TMPPLIST} 3>${WRKDIR}/.plist-dirs-unsorted \
	    >${WRKDIR}/.plist-files-unsorted
	unset TMPPLIST
	# Create the -no-comments files and trim out @comment from the plists.
	# This is used for various tests later.
	sed -e '/^@comment/d' ${WRKDIR}/.plist-dirs-unsorted \
	    >${WRKDIR}/.plist-dirs-unsorted-no-comments
	sed -i '' -e 's/^@comment //' ${WRKDIR}/.plist-dirs-unsorted
	sed -e '/^@comment/d' ${WRKDIR}/.plist-files-unsorted | sort \
	    >${WRKDIR}/.plist-files-no-comments
	sed -e 's/^@comment //' ${WRKDIR}/.plist-files-unsorted | sort \
	    >${WRKDIR}/.plist-files
}

# lists an mtree file's contents, prefixed to dir.
listmtree() { # mtreefile prefix
	{
		echo '#mtree'
		sed 's/nochange$//;' $1
	} | tar -tf- | sed "s,^,$2/,;s,^$2/\.$,$2,;s,^$,/,"
}

### PRODUCE MTREE FILE
parse_mtree() {
	{
		listmtree /etc/mtree/BSD.root.dist ""
		listmtree /etc/mtree/BSD.usr.dist /usr
		listmtree /etc/mtree/BSD.var.dist /var

		# Use MTREE_FILE if specified and it doesn't already
		# match LOCALBASE
		if [ -n "${MTREE_FILE}" ]; then
			if [ "${PREFIX}" != "${LOCALBASE}" -o "${MTREE_FILE}" \
			    != "${PORTSDIR}/Templates/BSD.local.dist" ]; then
				listmtree "${MTREE_FILE}" "${PREFIX}"
			fi
		fi
		listmtree "${PORTSDIR}/Templates/BSD.local.dist" "${LOCALBASE}"

		if [ -n "${GNOME_MTREE_FILE}" ] && \
		    [ -f "${GNOME_MTREE_FILE}" ]; then
			listmtree "${GNOME_MTREE_FILE}" "${PREFIX}"
		fi
		unset MTREE_FILE GNOME_MTREE_FILE

		# Add LOCALBASE
		a=${LOCALBASE}
		while :; do
			echo ${a}
			a=${a%/*}
			[ -z "${a}" ] && break
		done

		# Add in PREFIX if this port wants it
		if [ ${NO_PREFIX_RMDIR} -eq 0 ]; then
			a=${PREFIX}
			while :; do
				echo ${a}
				a=${a%/*}
				[ -z "${a}" ] && break
			done
		fi
	} >${WRKDIR}/.mtree
}

# Sort a directory list by the order of the dfs-sorted file (from find -ds)
sort_dfs() {
	while read dir; do
		grep "^[0-9]* ${dir}$" ${WRKDIR}/.staged-dirs-dfs-sorted
	done | sort -n | cut -d ' ' -f2-
}

# Prepare sed(1) regex for PLIST_SUB_SED/PORTEXAMPLES/OPTIONS/...
setup_plist_seds() {
	### HANDLE PORTDOCS/PORTEXAMPLES
	sed_portdocsexamples="/%%DOCSDIR%%/s!^!%%PORTDOCS%%!g; /%%EXAMPLESDIR%%/s!^!%%PORTEXAMPLES%%!g;"
	if [ ${makeplist} -eq 0 ]; then
	#	echo "=====> Using OPTIONS: ${PORT_OPTIONS}" | /usr/bin/fmt -w 79 | \
	#	    sed -e '2,$s/^/                      /'
		# Handle magical PORT* features
		for option in DOCS EXAMPLES; do
			want_option=0
			case " ${PORT_OPTIONS} " in
			*\ ${option}\ *) want_option=1 ;;
			esac
			[ ${want_option} -eq 0 ] && \
			    sed_portdocsexamples="${sed_portdocsexamples} /^%%PORT${option}%%/d;"
		done
		unset PORT_OPTIONS
	fi

	sed_plist_sub=$(echo "${PLIST_SUB_SED}" | /bin/sh ${SCRIPTSDIR}/plist_sub_sed_sort.sh)
	unset PLIST_SUB_SED
	# Used for generate_plist
	sed_files_gen="s!${PREFIX}/!!g; ${sed_plist_sub} \
	    ${sed_portdocsexamples} /^share\/licenses/d;"
	sed_dirs_gen="s!${PREFIX}/!!g; ${sed_plist_sub} s,^,@dir ,; \
	    ${sed_portdocsexamples} \
	    /^@dir share\/licenses/d;"

	# These prevent ignoring DOCS/EXAMPLES dirs with sed_portdocsexamples
	sed_files="s!${PREFIX}/!!g; ${sed_plist_sub} /^share\/licenses/d;"
	sed_dirs="s!${PREFIX}/!!g; ${sed_plist_sub} s,^,@dir ,; \
	    /^@dir share\/licenses/d;"

}

# Generate plist from staged files
generate_plist() {
	: >${WRKDIR}/.staged-plist

	### HANDLE FILES
	find ${STAGEDIR} -type f -o -type l | sort | \
	    sed -e "s,${STAGEDIR},," >${WRKDIR}/.staged-files
	comm -13 ${WRKDIR}/.plist-files ${WRKDIR}/.staged-files | \
	    sed -e "${sed_files_gen}" \
	     >>${WRKDIR}/.staged-plist || :

	### HANDLE DIRS
	cat ${WRKDIR}/.plist-dirs-unsorted ${WRKDIR}/.mtree \
	    | sort -u >${WRKDIR}/.traced-dirs
	find ${STAGEDIR} -type d | sed -e "s,^${STAGEDIR},,;/^$/d" | sort \
	    >${WRKDIR}/.staged-dirrms-sorted
	find -sd ${STAGEDIR}${PREFIX} -type d -empty | sed -e "s,^${STAGEDIR},,;\,^${PREFIX}$,d;/^$/d" \
	    >${WRKDIR}/.staged-dirs-dfs
	find -sd ${STAGEDIR} -type d ! -path "${STAGEDIR}${PREFIX}/*" | sed -e "s,^${STAGEDIR},,;\,^${PREFIX}$,d;/^$/d" \
	    >>${WRKDIR}/.staged-dirs-dfs
	sort ${WRKDIR}/.staged-dirs-dfs >${WRKDIR}/.staged-dirs-sorted
	awk '{print FNR, $0}' ${WRKDIR}/.staged-dirs-dfs \
	    >${WRKDIR}/.staged-dirs-dfs-sorted
	# Find all staged dirs and then sort them by depth-first (find -ds)
	comm -13 ${WRKDIR}/.traced-dirs ${WRKDIR}/.staged-dirs-sorted \
	    | sort_dfs | sed "${sed_dirs_gen}" \
	    >>${WRKDIR}/.staged-plist || :
}

# Check for files in STAGEDIR missing from plist
check_orphans_from_plist() {
	local ret=0

	echo "===> Checking for items in STAGEDIR missing from pkg-plist"
	# Handle whitelisting
	while read path; do
		case "${path}" in
		*.bak) ;;
		*.orig) ;;
		*/.DS_Store) ;;
		*/.cvsignore) ;;
		*/.git/*|'@dir '*/.git) ;;
		*/.gitattributes|*/.gitignore|*/.gitmodules) ;;
		*/.svn/*|'@dir '*/.svn) ;;
		*/.svnignore) ;;
		*/CVS/*|'@dir '*/CVS) ;;
		*/info/dir|info/dir) ;;
		lib/X11/fonts/*/fonts.dir) ;;
		lib/X11/fonts/*/fonts.scale) ;;
		share/applications/mimeinfo.cache) ;;
		share/mime/XMLnamespaces) ;;
		share/mime/aliases) ;;
		share/mime/generic-icons) ;;
		share/mime/globs) ;;
		share/mime/globs2) ;;
		share/mime/icons) ;;
		share/mime/magic) ;;
		share/mime/mime.cache) ;;
		share/mime/subclasses) ;;
		share/mime/treemagic) ;;
		share/mime/types) ;;
		share/mime/version) ;;
		*)
			# An orphan was found, return non-zero status
			ret=1
			echo "Error: Orphaned: ${path}" >&2
		;;
		esac
	done < ${WRKDIR}/.staged-plist
	return ${ret}
}

# Check for items in plist not in STAGEDIR (pkg lstat(2) errors)
check_missing_plist_items() {
	local ret=0
	echo "===> Checking for items in pkg-plist which are not in STAGEDIR"
	: >${WRKDIR}/.invalid-plist-missing
	comm -23 ${WRKDIR}/.plist-files-no-comments ${WRKDIR}/.staged-files | \
	    sed -e "${sed_files}" \
	    >>${WRKDIR}/.invalid-plist-missing || :

	# Look for directories, then sort them by DFS. Must create the dirs
	# so find -ds can be used to sort them.
	rm -rf ${WRKDIR}/.missing-dirs > /dev/null 2>&1 || :
	mkdir ${WRKDIR}/.missing-dirs
	comm -23 ${WRKDIR}/.plist-dirs-sorted-no-comments \
	    ${WRKDIR}/.staged-dirrms-sorted > ${WRKDIR}/.missing-plist-dirs
	# Creates the dirs in WRKDIR/.missing-dirs and ensure spaces are
	# quoted.
	sed -e "s,^,${WRKDIR}/.missing-dirs," \
	    -e 's,^\(.*\)$,"\1",' \
	    ${WRKDIR}/.missing-plist-dirs | xargs mkdir -p
	find -ds ${WRKDIR}/.missing-dirs | \
	    sed -e "s,^${WRKDIR}/.missing-dirs,," | \
	    while read dir; do \
	    grep -x "${dir}" ${WRKDIR}/.missing-plist-dirs || :; done | \
	    sed "${sed_dirs}" \
	    >>${WRKDIR}/.invalid-plist-missing || :
	rm -rf ${WRKDIR}/.missing-dirs
	if [ -s "${WRKDIR}/.invalid-plist-missing" ]; then
		ret=1
		while read line; do
			echo "Error: Missing: ${line}" >&2
		done < ${WRKDIR}/.invalid-plist-missing
	fi
	return ${ret}
}

# obtain operating mode from command line
ret=0
makeplist=0
case "$1" in
	checkplist)	;;
	makeplist)	makeplist=1 ;;
	*) echo >&2 "Usage: $0 {checkplist|makeplist}" ; exit 1 ;;
esac

# validate environment
envfault=
for i in STAGEDIR PREFIX LOCALBASE WRKDIR WRKSRC MTREE_FILE GNOME_MTREE_FILE \
    TMPPLIST PLIST_SUB_SED SCRIPTSDIR \
    PORT_OPTIONS NO_PREFIX_RMDIR
do
    if ! ( eval ": \${${i}?}" ) 2>/dev/null ; then
		envfault="${envfault}${envfault:+" "}${i}"
    fi
done
if [ -n "$envfault" ] ; then
	echo "Environment variables $envfault undefined. Aborting." \
	| fmt >&2
	exit 1
fi

set -u

if [ $makeplist = 0 ] ; then
	parse_plist
else
	# generate plist - pretend the plist had been empty
	: >${WRKDIR}/.plist-dirs-unsorted
	: >${WRKDIR}/.plist-files
	echo '/you/have/to/check/what/makeplist/gives/you'
fi

parse_mtree

setup_plist_seds
generate_plist

# If just making plist, show results and exit successfully.
if [ ${makeplist} -eq 1 ]; then
	cat ${WRKDIR}/.staged-plist
	exit 0
fi

check_orphans_from_plist || ret=1

# Prepare plist-dirs for directory checks
sort -u ${WRKDIR}/.plist-dirs-unsorted-no-comments \
    >${WRKDIR}/.plist-dirs-sorted-no-comments

check_missing_plist_items || ret=1

if [ ${ret} -ne 0 ]; then
	echo "===> Error: Plist issues found." >&2
	if [ "${PREFIX}" != "${LOCALBASE}" ]; then
	    echo "===> Warning: Test was done with PREFIX != LOCALBASE"
	    echo "===> Warning: The port may not be properly installing into PREFIX"
	fi
fi

exit ${ret}

# $FreeBSD$
#
# Make files or directories 'unique', by adding a prefix or suffix.
#
# Feature:		uniquefiles
# Usage:		USES=uniquefiles or USES=uniquefiles:ARGS
# Valid ARGS:	dirs
#
# dirs:			The port needs a prefix (and only a prefix) based on
#			UNIQUE_PREFIX for the standard directories
#			DOCSDIR, EXAMPLESDIR, DATADIR, WWWDIR, ETCDIR
#
# Variables for ports:
#
# UNIQUE_PREFIX		- The prefix to be used for directories and files.
#			  Default: ${PKGNAMEPREFIX}.
# UNIQUE_PREFIX_FILES	- A list of files that need to be prefixed.
#			  Default: empty
# UNIQUE_SUFFIX		- The suffix to be used for files.
#			  Default: ${PKGNAMESUFFIX}.
# UNIQUE_SUFFIX_FILES	- A list of files that need to be suffixed.
#			  Default: empty
#
# Variables for the ports framework, but NOT individual ports:
#
# UNIQUE_DEFAULT_LINKS	- When set to "yes", symlinks of the original
#			  filenames are also created pointing to their
#			  UNIQUE_* counterparts.
#			  This is useful for supporting multiple logical
#			  instances from a single physical port, but where
#			  you want to mark only *one* of those instances to
#			  provide original filenames.
#
#			  category/py-foo, installed as:
#
#			py27-foo for Python 2.7 (DEFAULT_VERSION)
#			py33-foo for Python 3.3
#
#			  Results in:
#
#			py27-foo
#			bin/foo-2.7             (UNIQUE_SUFFIX)
#			bin/foo -> bin/foo-2.7  (symlinked original filename)
#			py33-foo creates:
#			bin/foo-3.3             (UNIQUE_SUFFIX)
#
#			  Default: no
#
# UNIQUE_FIND_PREFIX_FILES	- A shell command to be executed to find files for
#				  the specific port. This has to return a
#				  list of files to be iterated over.
#				  Default: empty
#
# UNIQUE_FIND_SUFFIX_FILES	- A shell command to be executed to find files for
#				  the specific port. This has to return a
#				  list of files to be iterated over.
#				  Default: empty
#
# UNIQUE_SUFFIX_TYPES		- A list of TAGS to defined more complex unique
#				  suffix handling.  It can, for example, handle
#				  man pages by doing:
#
#		UNIQUE_SUFFIX_TYPES+=	SUFFIX_MAN
#		UNIQUE_SUFFIX_MAN_WITH_EXT=	.[1-9ln]
#		UNIQUE_SUFFIX_MAN_EXTRA_EXT=	.gz
#		UNIQUE_FIND_SUFFIX_MAN_FILES=	${EGREP} -he '^man/man[1-9ln]/.*$$' ${TMPPLIST} 2>/dev/null
#
#				  The make(1) target that renames the files
#				  runs before the man pages are compressed,
#				  this is what the EXTRA_EXT bit is for.
#
# NOTE:	multiple logical instances are not supported by pkg and the original
# pkg_tools at the moment.
#
# MAINTAINER:	portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_UNIQUEFILES_MK)
_INCLUDE_USES_UNIQUEFILES_MK=	yes

UNIQUE_PREFIX?=		${PKGNAMEPREFIX}
UNIQUE_SUFFIX?=		${PKGNAMESUFFIX}
UNIQUE_PREFIX_FILES?=	# empty
UNIQUE_SUFFIX_FILES?=	# empty

UNIQUE_SUFFIX_TYPES+=	SUFFIX

.if ${uniquefiles_ARGS:Mdirs}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUE_PREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${UNIQUE_PREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${UNIQUE_PREFIX}${PORTNAME}
WWWDIR=		${PREFIX}/www/${UNIQUE_PREFIX}${PORTNAME}
ETCDIR=		${PREFIX}/etc/${UNIQUE_PREFIX}${PORTNAME}
.endif

UNIQUE_DEFAULT_LINKS?=		no
UNIQUE_FIND_PREFIX_FILES?=	# empty
UNIQUE_FIND_SUFFIX_FILES?=	# empty

_USES_POST+=	uniquefiles
.endif # _INCLUDE_USES_UNIQUEFILES_MK

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_UNIQUEFILES_POST_MK)
_INCLUDE_USES_UNIQUEFILES_POST_MK=     yes

_UNIQUEPKGLIST=		${WRKDIR}/.PLIST.uniquefiles

.if ${UNIQUE_DEFAULT_LINKS} == yes
_DO_CONDITIONAL_SYMLINK=	\
	if [ ! -e ${STAGEDIR}${PREFIX}/$${fname} -a ! -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
		${ECHO_MSG} "Link: @$${fname} --> $${newf}"; \
		${RLN} ${STAGEDIR}${PREFIX}/$${newf} ${STAGEDIR}${PREFIX}/$${fname}; \
		${ECHO_CMD} LINKED:$${newf}%%EXTRA_EXT%%:$${fname}%%EXTRA_EXT%% >> ${_UNIQUEPKGLIST}; \
	fi
.else
# We are not symlinking the renamed binary.
_DO_CONDITIONAL_SYMLINK=	${DO_NADA}
.endif

_USES_stage+=	775:move-uniquefiles
move-uniquefiles:
.if ${UNIQUE_PREFIX_FILES} || ${UNIQUE_FIND_PREFIX_FILES}
	@${ECHO_MSG} "===> Creating unique files: Move files needing PREFIX";
.endif
.for entry in ${UNIQUE_PREFIX_FILES}
	@fname=${entry}; \
	if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
		newf=$${fname%/*}/${UNIQUE_PREFIX}$${fname##*/} ; \
		${ECHO_MSG} "Move: $${fname} --> $${newf}" ; \
		${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
		${ECHO_CMD} MOVED:$${fname}:$${newf} >> ${_UNIQUEPKGLIST}; \
		${_DO_CONDITIONAL_SYMLINK:S/%%EXTRA_EXT%%//g}; \
	else \
		${ECHO_MSG} "Makefile error: UNIQUE (prefix): $${fname} not found"; \
		${FALSE}; \
	fi;
.endfor
.if ${UNIQUE_FIND_PREFIX_FILES}
	@for fname in `${UNIQUE_FIND_PREFIX_FILES}`; do \
		if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
			newf=$${fname%/*}/${UNIQUE_PREFIX}$${fname##*/} ; \
			${ECHO_MSG} "Move: $${fname} --> $${newf}" ; \
			${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
			${ECHO_CMD} MOVED:$${fname}:$${newf} >> ${_UNIQUEPKGLIST}; \
			${_DO_CONDITIONAL_SYMLINK:S/%%EXTRA_EXT%%//g}; \
		else \
			${ECHO_MSG} "Makefile error: UNIQUE (prefix): $${fname} not found"; \
			${FALSE}; \
		fi; \
	done;
.endif

.for sufxtype in ${UNIQUE_SUFFIX_TYPES}
.  if (defined(UNIQUE_${sufxtype}_FILES) && ${UNIQUE_${sufxtype}_FILES}) || \
     (defined(UNIQUE_FIND_${sufxtype}_FILES) && ${UNIQUE_FIND_${sufxtype}_FILES})
.    if defined(UNIQUE_${sufxtype}_WITH_EXT) && ${UNIQUE_${sufxtype}_WITH_EXT}
	@${ECHO_MSG} "===> Creating unique files: Move ${sufxtype:S|SUFFIX_||} files needing SUFFIX";
.    else
	@${ECHO_MSG} "===> Creating unique files: Move files needing SUFFIX";
.    endif
.  endif
.  for entry in ${UNIQUE_${sufxtype}_FILES}
	@fname=${entry}; \
	if [ -n "${UNIQUE_${sufxtype}_EXTRA_EXT}" ]; then \
		fname=$${fname%${UNIQUE_${sufxtype}_EXTRA_EXT}}; \
	fi; \
	if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
		ofname=$${fname##*/}; \
		newf=$${fname%/*}/$${ofname%${UNIQUE_${sufxtype}_WITH_EXT}}${UNIQUE_SUFFIX}$${ofname#$${ofname%${UNIQUE_${sufxtype}_WITH_EXT}}}; \
		${ECHO_MSG} "Move: $${fname} --> $${newf}"; \
		${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
		${ECHO_CMD} MOVED:$${fname}${UNIQUE_${sufxtype}_EXTRA_EXT}:$${newf}${UNIQUE_${sufxtype}_EXTRA_EXT} >> ${_UNIQUEPKGLIST}; \
		${_DO_CONDITIONAL_SYMLINK:S/%%EXTRA_EXT%%/${UNIQUE_${sufxtype}_EXTRA_EXT}/g}; \
	else \
		${ECHO_MSG} "Makefile error: UNIQUE (suffix): $${fname} not found"; \
		${FALSE}; \
	fi;
.  endfor
.  if defined(UNIQUE_FIND_${sufxtype}_FILES) && ${UNIQUE_FIND_${sufxtype}_FILES}
	@for fname in `${UNIQUE_FIND_${sufxtype}_FILES}`; do \
		if [ -n "${UNIQUE_${sufxtype}_EXTRA_EXT}" ]; then \
			fname=$${fname%${UNIQUE_${sufxtype}_EXTRA_EXT}}; \
		fi; \
		if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
			ofname=$${fname##*/}; \
			newf=$${fname%/*}/$${ofname%${UNIQUE_${sufxtype}_WITH_EXT}}${UNIQUE_SUFFIX}$${ofname#$${ofname%${UNIQUE_${sufxtype}_WITH_EXT}}}; \
			${ECHO_MSG} "Move: $${fname} --> $${newf}"; \
			${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
			${ECHO_CMD} MOVED:$${fname}${UNIQUE_${sufxtype}_EXTRA_EXT}:$${newf}${UNIQUE_${sufxtype}_EXTRA_EXT} >> ${_UNIQUEPKGLIST}; \
			${_DO_CONDITIONAL_SYMLINK:S/%%EXTRA_EXT%%/${UNIQUE_${sufxtype}_EXTRA_EXT}/g}; \
		else \
			${ECHO_MSG} "Makefile error: UNIQUE (suffix): $${fname} not found"; \
			${FALSE}; \
		fi; \
	done;
.  endif
.endfor

# Using .if exists(${_UNIQUEPKGPLIST} below instead of the sh test
# does not work in poudriere. It works fine on the CLI, though...
_USES_stage+=	950:move-uniquefiles-plist
move-uniquefiles-plist:
	@if [ -e ${_UNIQUEPKGLIST} ]; then \
		orgIFS=$$IFS; IFS=":"; while read command entry newentry; do \
			IFS=$$orgIFS; \
			case $${command} in \
			MOVED) \
				${REINPLACE_CMD} -e "s|^$${entry}$$|$${newentry}|" ${TMPPLIST}; \
				;; \
			LINKED) \
				${AWK} '$$0 ~ pe { print; print ne ;next }1' \
					pe="$${entry}" ne="$${newentry}" \
					${TMPPLIST} > ${TMPPLIST}.uniquefilestmp; \
				${MV} ${TMPPLIST}.uniquefilestmp ${TMPPLIST}; \
				;; \
			*) ;; \
			esac; \
			IFS=":"; \
		done < ${_UNIQUEPKGLIST}; \
	fi

.endif # defined(_POSTMKINCLUDED)

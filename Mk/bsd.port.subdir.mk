#	from: @(#)bsd.subdir.mk	5.9 (Berkeley) 2/1/91
# $FreeBSD$
#
# The include file <bsd.port.subdir.mk> contains the default targets
# for building ports subdirectories.
#
#
# +++ variables +++
#
# STRIP		- The flag passed to the install program to cause the binary
#		  to be stripped.  This is to be used when building your
#		  own install script so that the entire system can be made
#		  stripped/not-stripped using a single knob. [-s]
#
# OPSYS		- Get the operating system type [`uname -s`]
#
# SUBDIR	- A list of subdirectories that should be built as well.
#		  Each of the targets will execute the same target in the
#		  subdirectories.
#
#
# +++ targets +++
#
#	README.html:
#		Creating README.html for package.
#
#	afterinstall, all, beforeinstall, build, checksum, clean,
#	clean-for-cdrom, clean-restricted,
#	clean-for-cdrom-list, clean-restricted-list,
#	configure, deinstall,
#	depend, depends, describe, extract, fetch, fetch-list,
#	ignorelist, ignorelist-verbose,
#	install, maintainer, makesum, package, readmes, realinstall, reinstall,
#	tags
#
#	search:
#		Search for ports using either 'make search key=<keyword>'
#		or 'make search name=<keyword>'.

PORTSDIR?=		/usr/ports
TEMPLATES?=		${PORTSDIR}/Templates
.if defined(PORTSTOP)
README=			${TEMPLATES}/README.top
.else
README=			${TEMPLATES}/README.category
.endif
MOVEDDIR?=		${PORTSDIR}
MOVEDFILE?=		MOVED

.include "${PORTSDIR}/Mk/bsd.commands.mk"

.MAIN: all

.if !defined(DEBUG_FLAGS)
STRIP?=	-s
.endif

# These are variables that are invariant for the lifetime of a recursive port traversal
# (index build, etc), so it is more efficient to precompute them here and pass them in
# to child makes explicitly, instead of recomputing them tens of thousands of times.

.if !defined(NOPRECIOUSMAKEVARS)
.if !defined(ARCH)
ARCH!=	${UNAME} -p
.endif
_EXPORTED_VARS+=	ARCH

.if !defined(OSVERSION)
.if exists(/usr/include/sys/param.h)
OSVERSION!=	${AWK} '/^\#define[[:blank:]]__FreeBSD_version/ {print $$3}' < /usr/include/sys/param.h
.elif exists(${SRC_BASE}/sys/sys/param.h)
OSVERSION!=	${AWK} '/^\#define[[:blank:]]__FreeBSD_version/ {print $$3}' < ${SRC_BASE}/sys/sys/param.h
.else
OSVERSION!=	${SYSCTL} -n kern.osreldate
.endif
.endif
_EXPORTED_VARS+=	OSVERSION

WITH_PKG=	yes
WITH_PKGNG=	yes

.if !defined(_OSRELEASE)
_OSRELEASE!=		${UNAME} -r
.endif
_EXPORTED_VARS+=	_OSRELEASE
.if !defined(OSREL)
OSREL=	${_OSRELEASE:C/[-(].*//}
.endif
_EXPORTED_VARS+=	OSREL

.if !defined(OPSYS)
OPSYS!=	${UNAME} -s
.endif
_EXPORTED_VARS+=	OPSYS

.if ${ARCH} == "amd64" || ${ARCH} =="ia64"
.if !defined(HAVE_COMPAT_IA32_KERN)
HAVE_COMPAT_IA32_KERN!= if ${SYSCTL} -n compat.ia32.maxvmem >/dev/null 2>&1; then echo YES; fi; echo
.if empty(HAVE_COMPAT_IA32_KERN)
.undef HAVE_COMPAT_IA32_KERN
.endif
.endif
.endif
_EXPORTED_VARS+=	HAVE_COMPAT_IA32_KERN

.if !defined(CONFIGURE_MAX_CMD_LEN)
CONFIGURE_MAX_CMD_LEN!= ${SYSCTL} -n kern.argmax
.endif
_EXPORTED_VARS+=	CONFIGURE_MAX_CMD_LEN

.if !defined(_JAVA_VERSION_LIST_REGEXP)
_JAVA_VERSION_LIST_REGEXP!=	${MAKE} -V _JAVA_VERSION_LIST_REGEXP USE_JAVA=1 -f ${PORTSDIR}/Mk/bsd.port.mk
.endif
_EXPORTED_VARS+=	_JAVA_VERSION_LIST_REGEXP

.if !defined(_JAVA_VENDOR_LIST_REGEXP)
_JAVA_VENDOR_LIST_REGEXP!=	${MAKE} -V _JAVA_VENDOR_LIST_REGEXP USE_JAVA=1 -f ${PORTSDIR}/Mk/bsd.port.mk
.endif
_EXPORTED_VARS+=	_JAVA_VENDOR_LIST_REGEXP

.if !defined(_JAVA_OS_LIST_REGEXP)
_JAVA_OS_LIST_REGEXP!=		${MAKE} -V _JAVA_OS_LIST_REGEXP USE_JAVA=1 -f ${PORTSDIR}/Mk/bsd.port.mk
.endif
_EXPORTED_VARS+=	_JAVA_OS_LIST_REGEXP

.if !defined(_JAVA_PORTS_INSTALLED)
_JAVA_PORTS_INSTALLED!=		${MAKE} -V _JAVA_PORTS_INSTALLED USE_JAVA=1 -f ${PORTSDIR}/Mk/bsd.port.mk
.endif
_EXPORTED_VARS+=	_JAVA_PORTS_INSTALLED

.if !defined(UID)
UID!=	${ID} -u
.endif
_EXPORTED_VARS+=	UID

.endif

INDEXDIR?=	${PORTSDIR}
INDEXFILE?=	INDEX-${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}

# local customization of the ports tree
.sinclude "${.CURDIR}/Makefile.local"

TARGETS+=	all
TARGETS+=	build
TARGETS+=	checksum
TARGETS+=	clean
TARGETS+=	clean-for-cdrom
TARGETS+=	clean-for-cdrom-list
TARGETS+=	clean-restricted
TARGETS+=	clean-restricted-list
TARGETS+=	configure
TARGETS+=	deinstall
TARGETS+=	depend
TARGETS+=	depends
TARGETS+=	distclean
TARGETS+=	extract
TARGETS+=	fetch
TARGETS+=	fetch-list
TARGETS+=	ignorelist
TARGETS+=	ignorelist-verbose
TARGETS+=	makesum
TARGETS+=	maintainer
TARGETS+=	package
TARGETS+=	package-recursive
TARGETS+=	realinstall
TARGETS+=	reinstall
TARGETS+=	tags

.for __target in ${TARGETS}
.if !target(${__target})
.if defined(SUBDIR) && !empty(SUBDIR)
${__target}: ${SUBDIR:S/^/_/:S/$/.${__target}/}
.else
${__target}:
.endif
.endif
.endfor

.if defined(SUBDIR) && !empty(SUBDIR)

.for __target in ${TARGETS} checksubdirs describe readmes
${SUBDIR:S/^/_/:S/$/.${__target}/}: _SUBDIRUSE
.endfor

_SUBDIRUSE: .USE
	@OK=""; sub=${.TARGET:S/^_//:R}; \
	for dud in $$DUDS; do \
		if [ $${dud} = $$sub ]; then \
			OK="false"; \
			${ECHO_MSG} "===> ${DIRPRFX}$$sub skipped"; \
		fi; \
	done; \
	if test -d ${.CURDIR}/$${sub}.${MACHINE_ARCH}; then \
		edir=$${sub}.${MACHINE_ARCH}; \
	elif test -d ${.CURDIR}/$${sub}; then \
		edir=$${sub}; \
	else \
		OK="false"; \
		${ECHO_MSG} "===> ${DIRPRFX}$${sub} non-existent"; \
	fi; \
	if [ "$$OK" = "" ]; then \
		${ECHO_MSG} "===> ${DIRPRFX}$${edir}"; \
		cd ${.CURDIR}/$${edir}; \
		${MAKE} -B ${.TARGET:E:realinstall=install} \
			DIRPRFX=${DIRPRFX}$$edir/; \
	fi

.for _subdir in ${SUBDIR:S/^/_/}
${_subdir}::   ${_subdir:S/$/.all/}
.endfor

.endif

.if !target(install)
.if !target(beforeinstall)
beforeinstall:
.endif
.if !target(afterinstall)
afterinstall:
.endif
install: afterinstall
afterinstall: realinstall
realinstall: beforeinstall ${SUBDIR:S/^/_/:S/$/.realinstall/}
.endif

IGNOREDIR=	Mk Templates Tools distfiles packages pkg Keywords

.if !target(checksubdirs)
.if defined(PORTSTOP)
checksubdirs: checksubdir ${SUBDIR:S/^/_/:S/$/.checksubdirs/}
.else
checksubdirs: checksubdir
.endif
.endif

.if !target(checksubdir)
checksubdir:
	@for d in *; do \
	  if [ -d "$$d" ]; then \
	    found=0; \
	    for s in ${SUBDIR} ${IGNOREDIR}; do \
	      if [ "x$$s" = "x$$d" ]; then \
	        found=1; \
	        break; \
	      fi; \
	    done; \
	    if [ $$found = 0 ]; then \
	      ${ECHO_MSG} "Warning: directory $$d not in SUBDIR"; \
	    fi; \
	  fi; \
	done
	@for s in ${SUBDIR}; do \
	  if ! [ -d ${.CURDIR}/$$s ]; then \
	    ${ECHO_MSG} "Warning: directory $$s in SUBDIR does not exist"; \
	  fi \
	done
.endif

.if !target(describe)
.if defined(PORTSTOP)
# This is a bit convoluted to deal with the fact that make will overlap I/O from child make processes
# if they write more than 2k: this will corrupt the INDEX file.  make -P does not do this, but it adds
# extraneous output and redirects stderr, so we lose error reporting from child makes.  Instead we have
# to roll our own implementation of make -P and make sure that each child make writes to their own file,
# which we will combine at the end.  This gives substantial performance benefits over doing a make -j1

.if defined(BUILDING_INDEX)
describe: ${SUBDIR:S/^/describe./}

.for i in ${SUBDIR}
describe.$i:
	@cd ${.CURDIR}; ${MAKE} -B ${i:S/^/_/:S/$/.describe/} > ${INDEX_TMPDIR}/${INDEXFILE}.desc.${i}
.endfor
.else
describe: ${SUBDIR:S/^/_/:S/$/.describe/}
.endif
.else
describe:
	@for sub in ${SUBDIR}; do \
	if ${TEST} -d ${.CURDIR}/$${sub}; then \
		${ECHO_MSG} "===> ${DIRPRFX}$${sub}"; \
		cd ${.CURDIR}/$${sub}; \
		${MAKE} -B describe || \
			(${ECHO_CMD} "===> ${DIRPRFX}$${sub} failed" >&2; \
			exit 1) ;\
	else \
		${ECHO_MSG} "===> ${DIRPRFX}$${sub} non-existent"; \
	fi; \
	done
.endif
.endif

.if !target(readmes)
.if defined(PORTSTOP)
readmes: readme ${SUBDIR:S/^/_/:S/$/.readmes/}
	@${ECHO_MSG} "===>   Creating README.html for all ports"
	@perl ${PORTSDIR}/Tools/make_readmes < ${INDEXDIR}/${INDEXFILE}
.else
readmes: readme
.endif
.endif

.if !target(readme)
readme:
	@${RM} -f README.html
	@${MAKE} README.html
.endif

HTMLIFY=	${SED} -e 's/&/\&amp;/g' -e 's/>/\&gt;/g' -e 's/</\&lt;/g'

package-name:
	@${ECHO_CMD} ${.CURDIR} | ${SED} -e 's^.*/^^'

README.html:
	@${ECHO_CMD} "===>  Creating README.html"
	@> $@.tmp
.for entry in ${SUBDIR}
.if exists(${entry})
.if defined(PORTSTOP)
	@${ECHO_CMD} -n '<a href="'${entry}/README.html'">'"`${ECHO_CMD} ${entry} | ${HTMLIFY}`"'</a>: ' >> $@.tmp
.else
	@${ECHO_CMD} -n '<a href="'${entry}/README.html'">'"`cd ${entry}; ${MAKE} package-name | ${HTMLIFY}`</a>: " >> $@.tmp
.endif
	@${ECHO_CMD} `cd ${entry}; ${MAKE} -V COMMENT` | ${HTMLIFY} >> $@.tmp
.endif
.endfor
	@${SORT} -t '>' +1 -2 $@.tmp > $@.tmp2
.if exists(${DESCR})
	@${HTMLIFY} ${DESCR} > $@.tmp3
.else
	@> $@.tmp3
.endif
.if defined(COMMENT)
	@${ECHO_CMD} "${COMMENT}" | ${HTMLIFY} > $@.tmp4
.else
	@> $@.tmp4
.endif
	@${CAT} ${README} | \
		${SED} -e 's/%%CATEGORY%%/'"`basename ${.CURDIR}`"'/g' \
			-e '/%%COMMENT%%/r$@.tmp4' \
			-e '/%%COMMENT%%/d' \
			-e '/%%DESCR%%/r$@.tmp3' \
			-e '/%%DESCR%%/d' \
			-e '/%%SUBDIR%%/r$@.tmp2' \
			-e '/%%SUBDIR%%/d' \
		> $@
	@${RM} -f $@.tmp $@.tmp2 $@.tmp3 $@.tmp4

# Pass in the cached invariant variables to child makes.
.if !defined(NOPRECIOUSMAKEVARS)
.for var in ${_EXPORTED_VARS}
.if empty(.MAKEFLAGS:M${var}=*) && !empty(${var})
.MAKEFLAGS:	${var}=${${var}:Q}
.endif
.endfor
.endif

PORTSEARCH_DISPLAY_FIELDS?=name,path,info,maint,index,bdeps,rdeps,www
PORTSEARCH_KEYLIM?=0
PORTSEARCH_XKEYLIM?=0
PORTSEARCH_IGNORECASE?=1
PORTSEARCH_MOVED?=1

_PORTSEARCH=	\
	here=${.CURDIR}; \
	if [ ! -r ${INDEXDIR}/${INDEXFILE} ] ; then \
		${ECHO_MSG} "The ${.TARGET} target requires ${INDEXFILE}. Please run make index or make fetchindex."; \
	else \
	cd ${PORTSDIR}; \
	if [ -z "$$key"   -a -z "$$xkey"   -a \
	     -z "$$name"  -a -z "$$xname"  -a \
	     -z "$$path"  -a -z "$$xpath"  -a \
	     -z "$$info"  -a -z "$$xinfo"  -a \
	     -z "$$maint" -a -z "$$xmaint" -a \
	     -z "$$cat"   -a -z "$$xcat"   -a \
	     -z "$$bdeps" -a -z "$$xbdeps" -a \
	     -z "$$rdeps" -a -z "$$xrdeps" -a \
	     -z "$$www"   -a -z "$$xwww"   ]; \
	then \
	  ${ECHO_MSG} "The ${.TARGET} target requires a keyword parameter or name parameter,"; \
	  ${ECHO_MSG} "e.g.: \"make ${.TARGET} key=somekeyword\""; \
	  ${ECHO_MSG} "or    \"make ${.TARGET} name=somekeyword\""; \
	  exit; \
	fi; \
	${AWK} -F\| -v there="$$here/" -v top="$$(pwd -P)" \
	    -v key="$$key"          -v xkey="$$xkey" \
	    -v name="$$name"        -v xname="$$xname" \
	    -v path="$$path"        -v xpath="$$xpath" \
	    -v info="$$info"        -v xinfo="$$xinfo" \
	    -v maint="$$maint"      -v xmaint="$$xmaint" \
	    -v cat="$$cat"          -v xcat="$$xcat" \
	    -v bdeps="$$bdeps"      -v xbdeps="$$xbdeps" \
	    -v rdeps="$$rdeps"      -v xrdeps="$$xrdeps" \
	    -v www="$$www"          -v xwww="$$xwww" \
	    -v icase="$${icase:-${PORTSEARCH_IGNORECASE}}" \
	    -v keylim="$${keylim:-${PORTSEARCH_KEYLIM}}" \
	    -v xkeylim="$${xkeylim:-${PORTSEARCH_XKEYLIM}}" \
	    -v display="$${display:-${PORTSEARCH_DISPLAY_FIELDS}}" \
	    -v xdisplay="$$xdisplay" \
	'BEGIN { \
            gsub(/\+/,"\\+",name); \
	    if (substr(there, 1, length(top)) == top) \
	      there = "${PORTSDIR}" substr(there, 1 + length(top)); \
	    therelen = length(there); \
	    keylen = length(key); keylim = keylim && keylen; \
	    if (!keylim && keylen) \
	      parms[0] = (icase ? tolower(key) : key); \
	    xkeylen = length(xkey); xkeylim = xkeylim && xkeylen; \
	    if (!xkeylim && xkeylen) \
	      xparms[0] = (icase ? tolower(xkey) : xkey); \
		if (icase) { \
	    if (length(name))  parms[1]  = tolower(name);  if (length(xname))  xparms[1]  = tolower(xname); \
	    if (length(path))  parms[2]  = tolower(path);  if (length(xpath))  xparms[2]  = tolower(xpath); \
	    if (length(info))  parms[4]  = tolower(info);  if (length(xinfo))  xparms[4]  = tolower(xinfo); \
	    if (length(maint)) parms[6]  = tolower(maint); if (length(xmaint)) xparms[6]  = tolower(xmaint); \
	    if (length(cat))   parms[7]  = tolower(cat);   if (length(xcat))   xparms[7]  = tolower(xcat); \
	    if (length(bdeps)) parms[8]  = tolower(bdeps); if (length(xbdeps)) xparms[8]  = tolower(xbdeps); \
	    if (length(rdeps)) parms[9]  = tolower(rdeps); if (length(xrdeps)) xparms[9]  = tolower(xrdeps); \
	    if (length(www))   parms[10] = tolower(www);   if (length(xwww))   xparms[10] = tolower(xwww); \
	  } else { \
	    if (length(name))  parms[1]  = name;  if (length(xname))  xparms[1]  = xname; \
	    if (length(path))  parms[2]  = path;  if (length(xpath))  xparms[2]  = xpath; \
	    if (length(info))  parms[4]  = info;  if (length(xinfo))  xparms[4]  = xinfo; \
	    if (length(maint)) parms[6]  = maint; if (length(xmaint)) xparms[6]  = xmaint; \
	    if (length(cat))   parms[7]  = cat;   if (length(xcat))   xparms[7]  = xcat; \
	    if (length(bdeps)) parms[8]  = bdeps; if (length(xbdeps)) xparms[8]  = xbdeps; \
	    if (length(rdeps)) parms[9]  = rdeps; if (length(xrdeps)) xparms[9]  = xrdeps; \
	    if (length(www))   parms[10] = www;   if (length(xwww))   xparms[10] = xwww; \
	  } \
	    fields["name"]  = 1;  names[1]  = "Port"; \
	    fields["path"]  = 2;  names[2]  = "Path"; \
	    fields["info"]  = 4;  names[4]  = "Info"; \
	    fields["maint"] = 6;  names[6]  = "Maint"; \
	    fields["cat"]   = 7;  names[7]  = "Index"; \
	    fields["bdeps"] = 8;  names[8]  = "B-deps"; \
	    fields["rdeps"] = 9;  names[9]  = "R-deps"; \
	    fields["www"]   = 10; names[10] = "WWW"; \
	    split(display, d, /,[ \t]*/); \
	    split(xdisplay, xd, /,[ \t]*/); \
	    for (i in d) { \
            toprint = 1; \
	      for (j in xd) { \
                if (d[i] == xd[j] ) { \
                       toprint=0; \
                       break; \
                 }\
	      } \
	    if (toprint == 1 ) disp[fields[d[i]]] = 1; \
	    } \
	  } \
	  { \
	    if (match($$2, "^/usr/ports/[^/]*/[^/]*$$") > 0) \
	      sub("^/usr/ports", "${PORTSDIR}", $$2); \
	    if (substr($$2, 1, therelen) != there) \
	      next; \
	    for (i in parms) \
	      if ((icase ? tolower($$i) : $$i) !~ parms[i]) \
	        next; \
	    for (i in xparms) \
	      if ((icase ? tolower($$i) : $$i) ~ xparms[i]) \
	        next; \
	    found = 0; \
	    for (i = 1; i < 11; i++) \
	      if (i in disp) { \
	        if (xkeylim && (icase ? tolower($$i) : $$i) ~ xkey) \
	          next; \
	        if (!found && keylim && (icase ? tolower($$i) : $$i) ~ key) \
	          found = 1; \
	      } \
	    if (keylim && !found) \
	      next; \
	    for (i = 1; i < 11; i++) \
	      if (i in disp) \
	        printf("%s:\t%s\n", names[i], $$i); \
	    print(""); \
	  }' ${INDEXDIR}/${INDEXFILE}; \
	  if [ "$$name" -o "$$xname" ] && [ ${PORTSEARCH_MOVED} -gt 0 ]; \
	  then \
	    ${AWK} -F\| -v name="$$name"        -v xname="$$xname" \
	        -v icase="$${icase:-${PORTSEARCH_IGNORECASE}}" \
	    'BEGIN { \
	        if (icase) { \
	    	if (length(name))  name = tolower(name);  if (length(xname))  xname = tolower(xname); \
	        } \
	        fields["name"]  = 1;  names[1]  = "Port"; \
	        fields["destination"]  = 2;  names[2]  = "Moved"; \
	        fields["date"]  = 3;  names[3]  = "Date"; \
	        fileds["reason"] = 4;  names[4] = "Reason"; \
	     } \
	    { \
		oldname = $$1;  newname = $$2; \
		if (oldname ~ /^\#/) next; \
		sub(".*\/", "", oldname);  newname = sub(".*\/", "", newname); \
	        if (((icase ? tolower(oldname) : oldname) ~ name) || \
		  ((icase ? tolower(newname) : newname) ~ name)) { \
	    	    for (i = 1; i <= 4; i++) { \
	    		printf("%s:\t%s\n", names[i], $$i); \
	    	    } \
	        print(""); \
	        } \
	    }' ${MOVEDDIR}/${MOVEDFILE}; \
	  fi \
	fi 

search:
	@${_PORTSEARCH}

quicksearch:
	@export display="name,path,info" ; \
	${_PORTSEARCH}

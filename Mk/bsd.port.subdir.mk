#	from: @(#)bsd.subdir.mk	5.9 (Berkeley) 2/1/91
# $FreeBSD$
#
# The include file <bsd.port.subdir.mk> contains the default targets
# for building ports subdirectories.
#
#
# +++ variables +++
#
# STRIP		The flag passed to the install program to cause the binary
#		to be stripped.  This is to be used when building your
#		own install script so that the entire system can be made
#		stripped/not-stripped using a single knob. [-s]
#
# ECHO_MSG	Used to print all the '===>' style prompts - override this
#		to turn them off [echo].
#
# OPSYS		Get the operating system type [`uname -s`]
#
# SUBDIR	A list of subdirectories that should be built as well.
#		Each of the targets will execute the same target in the
#		subdirectories.
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
#	depend, depends, describe, extract, fetch, fetch-list, ignorelist,
#	install, maintainer, makesum, package, readmes, realinstall, reinstall,
#	tags
#
#	search:
#		Search for ports using either 'make search key=<keyword>'
#		or 'make search name=<keyword>'.


.MAIN: all

.if !defined(DEBUG_FLAGS)
STRIP?=	-s
.endif

.if !defined(NOPRECIOUSMAKEVARS)
.if !defined(ARCH)
ARCH!=	/usr/bin/uname -p
.endif
.if !defined(OSREL)
OSREL!=	/usr/bin/uname -r | sed -e 's/[-(].*//'
.endif
.if !defined(OSVERSION)
.if exists(/sbin/sysctl)
OSVERSION!= /sbin/sysctl -n kern.osreldate
.else
OSVERSION!= /usr/sbin/sysctl -n kern.osreldate
.endif
.endif
.if !defined(PORTOBJFORMAT)
PORTOBJFORMAT!= test -x /usr/bin/objformat && /usr/bin/objformat || echo aout
.endif
.endif

ID?=	/usr/bin/id
UID!=	${ID} -u
LOCALBASE?=	${DESTDIR}/usr/local
.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_INFO?=	${LOCALBASE}/sbin/pkg_info
.else
PKG_INFO?=	/usr/sbin/pkg_info
.endif
SED?=		/usr/bin/sed
PKGINSTALLVER!=	${PKG_INFO} -P 2>/dev/null | ${SED} -e 's/.*: //'

.if !defined(OPSYS)
OPSYS!=	/usr/bin/uname -s
.endif

ECHO_MSG?=	echo

# local customization of the ports tree
.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

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
TARGETS+=	makesum
TARGETS+=	maintainer
TARGETS+=	package
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

IGNOREDIR=	CVS Mk Templates Tools distfiles packages pkg

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
	      ${ECHO} "Warning: directory $$d not in SUBDIR"; \
	    fi; \
	  fi; \
	done
	@for s in ${SUBDIR}; do \
	  if ! [ -d ${.CURDIR}/$$s ]; then \
	    ${ECHO} "Warning: directory $$s in SUBDIR does not exist"; \
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
	if test -d ${.CURDIR}/$${sub}; then \
		${ECHO_MSG} "===> ${DIRPRFX}$${sub}"; \
		cd ${.CURDIR}/$${sub}; \
		${MAKE} -B describe || \
			(echo "===> ${DIRPRFX}$${sub} failed" >&2; \
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
	@perl ${PORTSDIR}/Tools/make_readmes < ${PORTSDIR}/${INDEXFILE}
.else
readmes: readme
.endif
.endif

.if !target(readme)
readme:
	@rm -f README.html
	@make README.html
.endif

.if (${OPSYS} == "NetBSD")
PORTSDIR ?= /usr/opt
.else
PORTSDIR ?= /usr/ports
.endif
TEMPLATES ?= ${PORTSDIR}/Templates
.if defined(PORTSTOP)
README=	${TEMPLATES}/README.top
.else
README=	${TEMPLATES}/README.category
.endif
COMMENTFILE?=	${.CURDIR}/pkg/COMMENT
DESCR?=		${.CURDIR}/pkg/DESCR
.if ${OSVERSION} >= 600000
INDEXFILE?=	INDEX-6
.elif ${OSVERSION} >= 500036
INDEXFILE?=	INDEX-5
.else
INDEXFILE?=	INDEX
.endif

HTMLIFY=	sed -e 's/&/\&amp;/g' -e 's/>/\&gt;/g' -e 's/</\&lt;/g'

package-name:
	@echo ${.CURDIR} | sed -e 's^.*/^^'

README.html:
	@echo "===>  Creating README.html"
	@> $@.tmp
.for entry in ${SUBDIR}
.if exists(${entry})
.if defined(PORTSTOP)
	@echo -n '<a href="'${entry}/README.html'">'"`echo ${entry} | ${HTMLIFY}`"'</a>: ' >> $@.tmp
.else
	@echo -n '<a href="'${entry}/README.html'">'"`cd ${entry}; make package-name | ${HTMLIFY}`</a>: " >> $@.tmp
.endif
	@echo `cd ${entry}; make -V COMMENT` | ${HTMLIFY} >> $@.tmp
.endif
.endfor
	@sort -t '>' +1 -2 $@.tmp > $@.tmp2
.if exists(${DESCR})
	@${HTMLIFY} ${DESCR} > $@.tmp3
.else
	@> $@.tmp3
.endif
.if defined(COMMENT)
	@echo "${COMMENT}" | ${HTMLIFY} > $@.tmp4
.else
.if exists(${COMMENTFILE})
	@${HTMLIFY} ${COMMENTFILE} > $@.tmp4
.else
	@> $@.tmp4
.endif
.endif
	@cat ${README} | \
		sed -e 's/%%CATEGORY%%/'"`basename ${.CURDIR}`"'/g' \
			-e '/%%COMMENT%%/r$@.tmp4' \
			-e '/%%COMMENT%%/d' \
			-e '/%%DESCR%%/r$@.tmp3' \
			-e '/%%DESCR%%/d' \
			-e '/%%SUBDIR%%/r$@.tmp2' \
			-e '/%%SUBDIR%%/d' \
		> $@
	@rm -f $@.tmp $@.tmp2 $@.tmp3 $@.tmp4

.if !defined(NOPRECIOUSMAKEVARS)
.MAKEFLAGS: \
	ARCH="${ARCH:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OPSYS="${OPSYS:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSREL="${OSREL:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	OSVERSION="${OSVERSION:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	PORTOBJFORMAT="${PORTOBJFORMAT:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	UID="${UID:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}" \
	PKGINSTALLVER="${PKGINSTALLVER:S/"/"'"'"/g:S/\$/\$\$/g:S/\\/\\\\/g}"
.endif

PORTSEARCH_DISPLAY_FIELDS?=name,path,info,maint,index,bdeps,rdeps,www
PORTSEARCH_KEYLIM?=0
PORTSEARCH_XKEYLIM?=0
PORTSEARCH_IGNORECASE?=1

search: ${PORTSDIR}/${INDEXFILE}
	@here=${.CURDIR}; \
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
	  echo "The search target requires a keyword parameter or name parameter,"; \
	  echo "e.g.: \"make search key=somekeyword\""; \
	  echo "or    \"make search name=somekeyword\""; \
	  exit; \
	fi; \
	awk -F\| -v there="$$here/" -v top="$$(pwd -P)" \
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
	'BEGIN { \
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
	    for (i in d) { \
	      disp[fields[d[i]]] = 1; \
	    } \
	  } \
	  { \
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
	  }' ${PORTSDIR}/${INDEXFILE}

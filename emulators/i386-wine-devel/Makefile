# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	i386-

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	32bit Microsoft Windows compatibility environment for 64bit FreeBSD
LATEST_LINK=	${PKGNAMEPREFIX}wine-devel

# Use the wine port to do most of the heavy lifting
MASTERDIR=	${.CURDIR}/../wine-devel
PKGINSTALL=	${.CURDIR}/files/pkg-install
PKGDEINSTALL=	${PKGINSTALL}

ACTUAL-PACKAGE-DEPENDS=	${DO_NADA}
WINELIBDIR=	${PREFIX}/lib32
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin32 --libdir=${WINELIBDIR}
CONFLICTS=	wine-[0-9]*
PLIST_REINPLACE+=	winelib
PLIST_REINPLACE_WINELIB=	s!lib/!lib32/!g
WINE_SLAVE_BUILD=	yes
USE_LDCONFIG32=	${WINELIBDIR} ${WINELIBDIR}/wine

# Hook into post-install and do some adapting to make i386 binaries work nicely
# under FreeBSD/amd64 (include add dependant i386 libs)
post-install-script:
	# Install bounce script to access the 32bit executables
	${INSTALL_SCRIPT} ${.CURDIR}/files/binbounce ${PREFIX}/bin/wine
	for i in `grep ^bin ${TMPPLIST} | xargs -n1 basename` ; do \
		[ "$${i}" = "wine" ] || ${LN} -f ${PREFIX}/bin/wine ${PREFIX}/bin/$${i} ; \
		echo bin32/$${i} >> ${TMPPLIST} ; \
	done
	if [ -n "${WITH_PKGNG}" ]; then \
		echo '@dirrmtry bin32' >> ${TMPPLIST}; \
	else \
		echo '@unexec rmdir %D/bin32 2>/dev/null || true' >> ${TMPPLIST}; \
	fi
	# Find all libraries that are linked too (via ldd(1))
	grep -v '[@%]' ${TMPPLIST} | sed "s!^!${PREFIX}/!g" | \
	xargs -n1 file -F' ' | grep ELF | cut -f1 -d' ' | \
	env LD_LIBRARY_PATH=${PREFIX}/lib32:${LD_LIBRARY_PATH} xargs ldd -f '%p\n' \
	| sort -u | grep -v '^\(/usr\)\?/lib' | grep -v "^${PREFIX}/lib32/libwine.so" \
	| grep -v "^${PREFIX}/lib32/wine" > ${WRKDIR}/winelibs
	for i in `cat ${WRKDIR}/winelibs` ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/lib32/ ; \
		echo lib32/`basename $${i}` >> ${TMPPLIST} ; \
	done
	# Find all soft dependancies (via strings(1))
	grep -v '[@%]' ${TMPPLIST} | sed "s!^!${PREFIX}/!g" | \
	xargs -n1 file -F' ' | grep ELF | cut -f1 -d' ' | xargs strings | \
	grep '^lib.*\.so' | sort -u > ${WRKDIR}/winesoftlibs
	for i in `cat ${WRKDIR}/winesoftlibs` ; do \
		if [ -e ${LOCALBASE}/lib/$${i} ] && [ -z "`grep $${i} ${TMPPLIST}`" ] ; then \
			${INSTALL_DATA} ${LOCALBASE}/lib/$${i} ${PREFIX}/lib32/ ; \
			echo lib32/$${i} >> ${TMPPLIST} ; \
		fi ; \
	done
	if [ -n "${WITH_PKGNG}" ]; then \
		echo '@dirrmtry lib32' >> ${TMPPLIST}; \
	else \
		echo '@unexec rmdir %D/lib32 2>/dev/null || true' >> ${TMPPLIST}; \
	fi
	# Install nvidia patching script
	${INSTALL_SCRIPT} ${.CURDIR}/files/nvidia.sh ${DATADIR}/patch-nvidia.sh
	echo ${DATADIR:S|$(PREFIX)/||}/patch-nvidia.sh >> ${TMPPLIST}
	@${ECHO}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-package-script:
	if [ -n "${WITH_PKGNG}" ]; then \
		${XZ_CMD} -dc ${PKGFILE} | \
		${SED} -e "s/^\(arch: freebsd:.*:x86\):32/\1:64/" | \
		${XZ_CMD} > ${WRKDIR}/${PKGNAME}${PKG_SUFX}; \
		${MV} ${WRKDIR}/${PKGNAME}${PKG_SUFX} ${PKGFILE}; \
	fi

.include "${MASTERDIR}/Makefile"

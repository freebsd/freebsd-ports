# Created by: trevor
# $FreeBSD$

PORTNAME=	festival
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	FESTIVAL
DISTFILES=	${DISTNAME}-release.tar.gz	\
		speech_tools-${PORTVERSION}-release.tar.gz
DIST_SUBDIR=	festival

PATCHFILES=	src_modules_diphone_diphone.h.diff?id=b58a836:debian	\
		src_modules_diphone_di_io.cc.diff?id=b58a836:debian	\
		src_modules_diphone_diphone.cc.diff?id=b58a836:debian	\
		src_modules_donovan_t2s.h.diff?id=b58a836:debian	\
		src_modules_UniSyn_diphone_UniSyn_diphone.cc.diff?id=b58a836:debian	\
		festival_el_utf8.diff?id=b58a836:debian	\
		lintianspellpatch.diff?id=b58a836:debian	\
		hts21compat.diff?id=b58a836:debian	\
		languagespatch.diff?id=b58a836:debian	\
		${SPT_PATCHES:C/.*/patch-speech__tools_\0:netbsd/}
PATCH_SITES=	ftp://ftp.netbsd.org/pub/pkgsrc/current/pkgsrc/audio/festival/patches/:netbsd	\
		http://anonscm.debian.org/cgit/tts/festival.git/plain/debian/patches/:debian

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multi-lingual speech synthesis system

OPTIONS_DEFINE=	NAS
OPTIONS_DEFAULT=NAS

CXXFLAGS+=	-DFTLIBDIR=${LOCALBASE}/share/festival/lib
CONFIGURE_WRKSRC=${WRKDIR}/festival
USES=		gmake
SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival
MAKE_ARGS+=	CC="${CC}" GCC="${CC}" \
		CXX="${CXX}" GXX="${CXX}" \
		EST_HOME=${SPEECHTOOLS}
WRKSRC=		${WRKDIR}

SPT_PATCHES=	include_ling__class_EST__FeatureFunctionPackage.h	\
		include_unix_EST__socket__unix.h

do-build:
.for d in speech_tools festival
	${MAKE_CMD} -C ${WRKDIR}/$d ${MAKE_FLAGS} Makefile ${MAKE_ARGS}
.endfor

# Can not make test in `festival', because the voices may not be installed
# XXX: this should fail, if the verdict is not "CORRECT"...
post-build test:
	${MAKE_CMD} -C ${WRKDIR}/speech_tools test

# The below is needed, because Debian's patches expect a different
# directory-name
pre-patch:
	${LN} -s festival ${WRKSRC}/festival-2.1~release
	${LN} -s festival ${WRKSRC}/b

post-patch::
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g'	\
		${WRKSRC}/*/config/systems/default.mak

.for m in nas
${m:tu}_LIB_DEPENDS=	lib${m:nas=audio}.so:audio/${m}
post-patch-${m:tu}-on:
	${REINPLACE_CMD} -e 's,# INCLUDE_MODULES += ${m:tu}_AUDIO,INCLUDE_MODULES += ${m:tu}_AUDIO,' \
		${WRKDIR}/*/config/config.in
${m:tu}_CONFIGURE_ENABLE=${m}
.endfor

do-configure:
.for d in speech_tools festival
	@cd ${WRKDIR}/$d && \
		if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}; then \
		${ECHO_CMD} "===>  configuration script for $d failed."; \
		${FALSE}; \
	fi
	# This step helps non-i386 systems and is harmless on i386
	-${LN} -s ix86_FreeBSD.mak ${WRKDIR}/$d/config/systems/${MACHINE}_unknown.mak
.endfor
	@${REINPLACE_CMD} \
	    -e '/^CFLAGS *=/s|$$| ${CFLAGS}|' \
	    -e '/^CXXFLAGS *=/s|$$| ${CXXFLAGS}|' \
	    -e 's,^OPTIMI,#OPTIMI,' \
	    ${WRKSRC}/speech_tools/config/compilers/gcc*.mak

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} ${FESTIVAL} -type f -name *.orig -delete
	${CP} -pPR ${FESTIVAL}/lib ${FESTIVAL}/examples ${STAGEDIR}${DATADIR}
	${RM} -r ${STAGEDIR}${DATADIR}/lib/etc/Makefile ${STAGEDIR}${DATADIR}/lib/etc/*FreeBSD* \
	    ${STAGEDIR}${DATADIR}/lib/etc/*unknown
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/*/audsp ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival ${STAGEDIR}${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client ${STAGEDIR}${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; \
	do {\
	  ${SED} "s%@PKG_FESTIVAL_LOCATION@%${DATADIR}%; \
	       s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/$$n > ${WRKDIR}/$$n ;} \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${STAGEDIR}${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh ${STAGEDIR}${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${STAGEDIR}${DATADIR}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1 ${STAGEDIR}${PREFIX}/man/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1 ${STAGEDIR}${PREFIX}/man/man1/festival_client.1

.include <bsd.port.mk>

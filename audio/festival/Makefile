# Created by: trevor
# $FreeBSD$

PORTNAME=	festival
PORTVERSION=	1.96
PORTREVISION=	3
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	${DISTNAME}-beta.tar.gz 	\
		speech_tools-1.2.${PORTVERSION:E}-beta.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multi-lingual speech synthesis system

OPTIONS_DEFINE=	NAS ESD
OPTIONS_DEFAULT=	NAS ESD
ESD_DESC=	${ESOUND_DESC}

DIST_SUBDIR=	festival

CONFIGURE_WRKSRC=	${WRKDIR}/festival
USES=		gmake
SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival
MAKE_ENV+=	GCC="${CC}" \
		GXX="${CXX}" \
		EST_HOME=${SPEECHTOOLS} \
		EGCS_CC="${CC}" \
		EGCS_CXX="${CXX}"
MAN1=		festival.1 festival_client.1
WRKSRC=		${WRKDIR}

do-build:
.for d in speech_tools festival
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/$d ${MAKE_FLAGS} Makefile \
		${MAKE_ARGS}
.endfor

# Can not make test in `festival', because the voices may not be installed
# XXX: this should fail, if the verdict is not "Test OK"...
post-build test:
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/speech_tools test

post-patch::
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g'	\
		${WRKSRC}/*/config/systems/default.mak

.include <bsd.port.options.mk>

.for m in nas esd
.	if ${PORT_OPTIONS:M${m:U}}
LIB_DEPENDS+=	${m:nas=audio}:${PORTSDIR}/audio/${m:esd=esound}
post-patch::
	${REINPLACE_CMD} -e 's,# INCLUDE_MODULES += ${m:U}_AUDIO,INCLUDE_MODULES += ${m:U}_AUDIO,' \
		${WRKDIR}/*/config/config.in
CONFIGURE_ARGS+=--enable-$m
.	else
CONFIGURE_ARGS+=--disable-$m
.	endif
.endfor

do-configure:
.for d in speech_tools festival
	@cd ${WRKDIR}/$d && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}; then \
		${ECHO_CMD} "===>  configuration script for $d failed."; \
		${FALSE}; \
	fi
	# This step helps non-i386 systems and is harmless on i386
	-${LN} -s ix86_FreeBSD.mak ${WRKDIR}/$d/config/systems/${ARCH}_unknown.mak
	${REINPLACE_CMD} -E -e 's,^(CC|CXX) *=,\1 ?=,' \
	    -e 's,^(CFLAGS|CXXFLAGS) *=,\1 +=,'	\
	    -e 's,^OPTIMI,#OPTIMI,' \
	    ${WRKSRC}/speech_tools/config/compilers/gcc*.mak
.endfor
	# This step helps to use a compiler, the vendor has not seen before:
	${TEST} -e ${WRKDIR}/speech_tools/config/compilers/${CC}.mak ||	\
		${LN} -s gcc_defaults.mak ${WRKDIR}/speech_tools/config/compilers/${CC}.mak

do-install:
	${MKDIR} ${DATADIR}/lib/voices/english/
	${MKDIR} ${DATADIR}/lib/voices/spanish/
	${MKDIR} ${DATADIR}/lib/dicts
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	cd ${FESTIVAL} && ${CP} -pPR lib examples ${DATADIR}
	${RM} -rf ${DATADIR}/lib/etc/Makefile ${DATADIR}/lib/etc/*FreeBSD* \
	    ${DATADIR}/lib/etc/*unknown
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/*/audsp ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival ${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client ${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; \
	do {\
	  ${SED} "s%@PKG_FESTIVAL_LOCATION@%${DATADIR}%; \
	       s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/$$n > ${WRKDIR}/$$n ;} \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh ${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${DATADIR}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1 ${PREFIX}/man/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1 ${PREFIX}/man/man1/festival_client.1
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

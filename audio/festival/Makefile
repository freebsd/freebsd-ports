# New ports collection makefile for:	festival
# Date created:        			2000-06-11
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.11 1999/12/28 04:19:58 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festival
PORTVERSION=	1.95
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	${DISTNAME}-beta.tar.gz \
		speech_tools-1.2.95-beta.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-lingual speech synthesis system

LIB_DEPENDS=	audio.2:${PORTSDIR}/audio/nas \
		esd.2:${PORTSDIR}/audio/esound

DIST_SUBDIR=	festival

CONFIGURE_WRKSRC=	${WRKDIR}/festival
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival
FHOME=		${PREFIX}/share/festival
MAKE_ENV+=	GCC="${CC}" \
		GXX="${CXX}" \
		EST_HOME=${SPEECHTOOLS} \
		EGCS_CC="${CC}" \
		EGCS_CXX="${CXX}" \
		CC="${CC}" \
		CXX="${CXX}"
MAN1=		festival.1 festival_client.1
WRKSRC=		${WRKDIR}

do-configure:
.for ii in speech_tools festival
	@cd ${WRKDIR}/${ii} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}; then \
		${ECHO_CMD} "===>  configuration script for ${ii} failed."; \
		${FALSE}; \
	 fi
.endfor

do-build:
.for ii in speech_tools festival
	@(cd ${WRKDIR}/${ii}; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile ${MAKE_ARGS})
.endfor

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not build on !i386"
.endif

do-install:
	${MKDIR} ${FHOME}/lib/voices/english/
	${MKDIR} ${FHOME}/lib/voices/spanish/
	${MKDIR} ${FHOME}/lib/dicts
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	cd ${FESTIVAL} && ${CP} -pPR lib examples ${FHOME}
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/*FreeBSD*/audsp ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival ${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client ${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; \
	do {\
	  ${SED} "s%@PKG_FESTIVAL_LOCATION@%${FHOME}%; \
	       s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/$$n > ${WRKDIR}/$$n ;} \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh ${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${FHOME}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1 ${PREFIX}/man/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1 ${PREFIX}/man/man1/festival_client.1

.include <bsd.port.post.mk>

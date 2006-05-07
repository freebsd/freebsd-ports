# New ports collection makefile for:	ssamtse
# Date created:				25 November 2003
# Whom:					Sergey Akifyev
#
# $FreeBSD$
#

PORTNAME=	ssamtse
PORTVERSION=	b1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	# must fetch manually
DISTFILES=	${PORTNAME}-${PORTVERSION:S|b|beta|}.sh.bin
EXTRACT_ONLY=

MAINTAINER=	asa@gascom.ru
COMMENT=	Serious Sam - The Second Encounter

NO_BUILD=	yes
USE_BZIP2=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
INSTALLS_SHLIB=	yes
NO_PACKAGE=	yes	# distfiles must be downloaded manually, wierd legal issues etc etc etc.

SSAMDIR=	${PREFIX}/ssam
SERIOUS_MHZ?=	1000
PKGMESSAGE=	${WRKDIR}/pkgmsg

ONLY_FOR_ARCHS=	i386

pre-fetch:
	@if test ! -e "${DISTDIR}/${DISTFILES}"; then \
		${ECHO_MSG} "Warning: you should fetch distfiles for this port"; \
		${ECHO_MSG} "manually! Google for 'serious sam linux', and get"; \
		${ECHO_MSG} "following files into distdir:"; \
		${ECHO_MSG} "	${DISTFILES}"; \
		${ECHO_MSG} "I'll enable auto-fetch, when licensing issues"; \
		${ECHO_MSG} "become clear"; \
		${FALSE}; \
	fi

post-extract:
.if !exists("${WRKDIR}/ssam/")
	@${ECHO} n | ${SH} ${DISTDIR}/${DISTFILES} --keep --nox11 --confirm \
		--target ${WRKDIR}/ssam
	@${ECHO_MSG} ""
.endif
	@${MKDIR} ${WRKSRC}
	@${TAR} -C ${WRKSRC} -xzf ${WRKDIR}/ssam/setupstuff.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%SSAMTSE_DATA_PATH%|${SSAMDIR}/Bin|g' \
		-e 's|%SERIOUS_MHZ%|${SERIOUS_MHZ}|g' \
		${WRKSRC}/bin/ssamtse
	@${SED} 's|%SSAMDIR%|${SSAMDIR}|g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

do-install:
# XXX: this is missing "${BRANDELF} -t Linux <executables>"
	@${MKDIR} ${SSAMDIR}
	@${TAR} --bzip2 -C ${SSAMDIR} -xf \
		${WRKDIR}/ssam/bins.tar.bz2
	@${LN} -sf ${SSAMDIR}/Bin/libogg.so ${SSAMDIR}/Bin/libogg.so.0
	@${LN} -sf ${SSAMDIR}/Bin/libGameMP.so ${SSAMDIR}/Bin/libGame.so
	@${LN} -sf ${SSAMDIR}/Bin/libEntitiesMP.so ${SSAMDIR}/Bin/libEntities.so
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/ssamtse ${PREFIX}/bin/ssamtse
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

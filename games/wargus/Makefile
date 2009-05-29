# New ports collection makefile for:	wargus
# Date created:			1 Jul 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	wargus
PORTVERSION=	2.2.4
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warcraft 2 mod that allows you to play Warcraft 2 with Stratagus

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	stratagus:${PORTSDIR}/games/stratagus

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-a
NOT_FOR_ARCHS=	sparc64
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	${PORTNAME} pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	cd ${WRKSRC} && \
		${FIND} campaigns contrib maps scripts -type d \
		-exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} campaigns contrib maps scripts -type f \
		-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${INSTALL_PROGRAM} ${WRKSRC}/wartool ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/build.sh ${DATADIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>

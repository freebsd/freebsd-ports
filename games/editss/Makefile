# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	editss
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	LOCAL/jylefort

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editor for XPilot shipshapes

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		imake xorg
USE_XORG=	x11 xaw xmu xt
ALL_TARGET=	editss

SUB_FILES=	editss

post-patch:
	@${REINPLACE_CMD} -e 's|xxpms/ships2|.xpilot-shipshapes|' \
		${WRKSRC}/editssrc

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/editss ${STAGEDIR}${PREFIX}/bin/editss
	${INSTALL_PROGRAM} ${WRKSRC}/editss ${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editssrc ${WRKSRC}/ships ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/editss.6 ${STAGEDIR}${MANPREFIX}/man/man6

.include <bsd.port.mk>

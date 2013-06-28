# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	editss
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editor for XPilot shipshapes

USES=		imake
USE_XORG=	x11 xaw xmu xt
ALL_TARGET=	editss
MAN6=		editss.6
NO_INSTALL_MANPAGES=	yes
SUB_FILES=	editss

post-patch:
	@${REINPLACE_CMD} -e 's|xxpms/ships2|.xpilot-shipshapes|' \
		${WRKSRC}/editssrc

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/editss ${PREFIX}/bin/editss
	${INSTALL_PROGRAM} ${WRKSRC}/editss ${PREFIX}/libexec
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editssrc ${WRKSRC}/ships ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/editss.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>

# Created by: Alexander Gromnitsky
# $FreeBSD$

PORTNAME=	xoris
PORTVERSION=	0.1e
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	alexander.gromnitsky@gmail.com
COMMENT=	X11 pixel color grabber

USES=		imake
USE_XORG=	x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
SUB_FILES=	pkg-message
.endif

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/xoris-run.sh ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

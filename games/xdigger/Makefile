# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xdigger
PORTVERSION=	1.0.10
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Boulderdash-like KC85 Digger for X Window System

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake tar:tgz
USE_XORG=	x11 xext

DESKTOP_ENTRIES="XDigger" "" "" "${PORTNAME}" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/configure.h

post-install:
	${MV} ${STAGEDIR}/var/games/xdigger.hiscore \
		${STAGEDIR}/var/games/xdigger.hiscore.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

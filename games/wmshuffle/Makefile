# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmshuffle
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.linuks.mine.nu/dockapp/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable Shuffle game for WindowMaker and AfterStep

USE_XORG=	xpm
USES=		gmake

PLIST_FILES=	bin/wmshuffle \
		%%DATADIR%%/skin-feiticeira.xpm \
		%%DATADIR%%/skin-lucyenne.xpm
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		's|^void .*main|int main|' ${WRKSRC}/wmshuffle.c

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/skin-*.xpm ${STAGEDIR}${DATADIR}
	@${ECHO_MSG} "===>   Run 'wmshuffle --help' for the available options"

.include <bsd.port.mk>

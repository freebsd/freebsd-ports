# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	divide-and-succeed
PORTVERSION=	0.9.4
CATEGORIES=	games
MASTER_SITES=	http://projects.haxx.es/media/upload/${PORTNAME}/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Divide polygons into the rigth number of equal parts

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: Polygone.h: 'vector' was not declared in this scope

USES=		cmake:insource
USE_SDL=	sdl ttf
DATADIR=	${PREFIX}/share/divideandsucceed
INSTALLS_ICONS=	yes

post-install:
	${LN} -s ../../share/icons/hicolor/64x64/apps/divideandsucceed.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>

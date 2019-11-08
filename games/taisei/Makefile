# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	taisei
PORTVERSION=	1.1.2
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source Touhou clone

LICENSE=	MIT CC0-1.0 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libzip.so:archivers/libzip

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-project

USES=		cmake compiler:c11 pkgconfig sdl
CMAKE_ARGS=	-DTAISEI_VERSION_OVERRIDE=${PORTVERSION}
USE_SDL=	sdl2 ttf2 mixer2

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING.txt

.include <bsd.port.mk>

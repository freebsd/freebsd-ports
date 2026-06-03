PORTNAME=	armagetronad
DISTVERSION=	0.2.9.3.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/stable/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tron clone in 3D
WWW=		http://www.armagetronad.org/ \
		https://github.com/ArmagetronAd/armagetronad

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libZThread.so:devel/zthread

USES=		autoreconf desktop-file-utils gl gmake gnome pkgconfig sdl \
		tar:tbz
USE_CXXSTD=	c++14
USE_GL=		gl glu
USE_GNOME=	libxml2
USE_SDL=	image mixer sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-etc --disable-games --disable-uninstall --enable-music

BINARY_ALIAS=	sdl11-config=sdl-config

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

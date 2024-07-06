PORTNAME=	manaplus
DISTVERSION=	2.1.3.17
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://download.evolonline.org/manaplus/download/${PORTVERSION}/

MAINTAINER=	ports@freebsd.org
COMMENT=	Free open source 2D MMORPG client for athena and evol servers
WWW=		https://www.manaplus.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Fails to build with libxml2 2.13.2 (PR 279705)
EXPIRATION_DATE=2024-08-06

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl

USES=		autoreconf compiler:c++11-lang pkgconfig:build sdl tar:xz xorg
USE_CXXSTD=	c++11
USE_SDL=	sdl2 gfx2 image2 mixer2 net2 ttf2
USE_XORG=	x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-sdl2 \
		--without-internalsdlgfx

OPTIONS_DEFINE=		OPENGL NLS
OPTIONS_DEFAULT=	OPENGL
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_ENABLE=	nls
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl
OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_CONFIGURE_WITH=	opengl

.include <bsd.port.mk>

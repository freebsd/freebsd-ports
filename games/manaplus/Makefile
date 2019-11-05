# Created by: Tobias Gion
# $FreeBSD$

PORTNAME=	manaplus
DISTVERSION=	1.9.3.23
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.evolonline.org/manaplus/download/${PORTVERSION}/

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Free open source 2D MMORPG client for athena and evol servers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl

USES=		autoreconf compiler:c++11-lang pkgconfig:build sdl tar:xz xorg
USE_XORG=	x11
USE_SDL=	sdl2 gfx2 image2 mixer2 net2 ttf2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl2 \
		--without-internalsdlgfx

OPTIONS_DEFINE=		OPENGL NLS
OPTIONS_DEFAULT=	OPENGL
OPTIONS_SUB=		yes

OPENGL_CONFIGURE_WITH=	opengl
OPENGL_USES=		gl
OPENGL_USE=		GL=gl

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

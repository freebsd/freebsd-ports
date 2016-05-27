# Created by: Tobias Gion
# $FreeBSD$

PORTNAME=	manaplus
PORTVERSION=	1.5.12.5
CATEGORIES=	games
MASTER_SITES=	http://download.evolonline.org/manaplus/download/${PORTVERSION}/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Free open source 2D MMORPG client for athena and evol servers

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libphysfs.so:devel/physfs

USES=		gettext pkgconfig:build tar:xz
USE_SDL=	sdl2 gfx2 image2 mixer2 net2 ttf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --with-sdl2 \
		--without-internalsdlgfx
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=		OPENGL
OPTIONS_DEFAULT=	OPENGL

OPENGL_CONFIGURE_WITH=	opengl
OPENGL_USE=		GL=yes

.include <bsd.port.mk>

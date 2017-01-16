# Created by: Tobias Gion
# $FreeBSD$

PORTNAME=	manaplus
PORTVERSION=	1.7.1.7
CATEGORIES=	games
MASTER_SITES=	http://download.evolonline.org/manaplus/download/${PORTVERSION}/

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Free open source 2D MMORPG client for athena and evol servers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libphysfs.so:devel/physfs

USES=		autoreconf pkgconfig:build tar:xz
USE_XORG=	x11
USE_SDL=	sdl2 gfx2 image2 mixer2 net2 ttf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl2 \
		--without-internalsdlgfx

OPTIONS_DEFINE=		OPENGL NLS
OPTIONS_DEFAULT=	OPENGL
OPTIONS_SUB=		yes

OPENGL_CONFIGURE_WITH=	opengl
OPENGL_USE=		GL=gl

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_LDFLAGS=		-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

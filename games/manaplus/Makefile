# Created by: Tobias Gion
# $FreeBSD$

PORTNAME=	manaplus
PORTVERSION=	1.4.3.15
CATEGORIES=	games
MASTER_SITES=	http://download.evolonline.org/manaplus/download/${PORTVERSION}/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Free open source 2D MMORPG client for athena and evol servers

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libphysfs.so:${PORTSDIR}/devel/physfs

USES=		gettext pkgconfig:build tar:xz
USE_SDL=	sdl gfx image mixer net ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		OPENGL
OPTIONS_DEFAULT=	OPENGL

OPENGL_CONFIGURE_WITH=	opengl
OPENGL_USE=		GL=yes

.include <bsd.port.mk>

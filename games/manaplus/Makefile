# Created by: Tobias Gion
# $FreeBSD$

PORTNAME=	manaplus
PORTVERSION=	1.3.11.10
CATEGORIES=	games
MASTER_SITES=	http://download.evolonline.org/manaplus/download/${PORTVERSION}/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Free open source 2D MMORPG in development

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libphysfs.so:${PORTSDIR}/devel/physfs \
		libguichan.so:${PORTSDIR}/devel/guichan

USES=		gettext pkgconfig:build
USE_XZ=		yes
USE_SDL=	sdl gfx image mixer net ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-internalguichan \
		--with-libintl-prefix=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		OPENGL
OPTIONS_DEFAULT=	OPENGL

OPENGL_CONFIGURE_WITH=	opengl
OPENGL_USE=		GL=yes

.include <bsd.port.mk>

# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goom
PORTVERSION=	2k4.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2k4/0
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual effects library

LICENSE=	LGPL20

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S|.|-|}
USES=		pathfix libtool localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-sdltest --enable-static
CONFIGURE_ENV=	ac_cv_path_SDL_CONFIG="no"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

BROKEN_powerpc=	Does not build

OPTIONS_DEFINE=	XMMS
OPTIONS_SUB=	yes

XMMS_DESC=		Build XMMS visualization plugin
XMMS_LIB_DEPENDS=	libxmms.so:multimedia/xmms
XMMS_USES=		gettext-runtime
XMMS_USE=		GNOME=glib12,gtk12 \
			XORG=x11,xext,xi
XMMS_CONFIGURE_ENV_OFF=	ac_cv_path_XMMS_CONFIG="no"

.include <bsd.port.mk>

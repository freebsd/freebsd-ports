# New ports collection makefile for:   panoglview
# Date created:        Sat Apr 28 07:59:00 UTC 2007
# Whom:                argv[0] (Iouri V. Ivliev)
#
# $FreeBSD$
#

PORTNAME=	panoglview
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin

MAINTAINER=	ii@any.com.ru
COMMENT=	Panorama viewer using OpenGL

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include -ftemplate-depth-64" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -lwx_gtk2_gl-${WX_VERSION}" \
		WX_CONFIG_NAME=wxgtk2-${WX_VERSION}-config \
		PATH="$${PATH}:${LOCALBASE}/bin"
USE_XORG=	x11
USE_GMAKE=	yes

USE_WX=		2.6+
WX_COMPS=	wx
WX_CONF_ARGS=	relative

PLIST_FILES=	bin/panoglview

OPTIONS=	UNICODE	"Use UNICODE version of the wxgtk (NLS broken!)"	off

.include <bsd.port.pre.mk>

.if defined(WITH_UNICODE)
WX_UNICODE=	yes
WX_RC=		wxrc-gtk2u-${WX_VERSION}
CONFIGURE_ARGS+=	--with-unicode
.else
WX_RC=		wxrc-gtk2-${WX_VERSION}
CONFIGURE_ARGS+=	--without-unicode
.endif

.include <bsd.port.post.mk>

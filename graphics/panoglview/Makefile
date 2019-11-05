# Created by: argv[0] (Iouri V. Ivliev)
# $FreeBSD$

PORTNAME=	panoglview
PORTVERSION=	0.2.2
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Panorama viewer using OpenGL

USES=		compiler:c++11-lang gl gmake
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unicode
CONFIGURE_ENV=	WX_CONFIG_NAME=${WX_CONFIG} \
		PATH="$${PATH}:${LOCALBASE}/bin"
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include -ftemplate-depth-64
LIBS+=		-L${LOCALBASE}/lib -lGLU -lGL

USE_WX=		3.0
WX_COMPS=	wx
WX_CONF_ARGS=	relative

PLIST_FILES=	bin/panoglview

.include <bsd.port.mk>

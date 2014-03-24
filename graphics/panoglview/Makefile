# Created by: argv[0] (Iouri V. Ivliev)
# $FreeBSD$

PORTNAME=	panoglview
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Panorama viewer using OpenGL

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WX_CONFIG_NAME=${WX_CONFIG} \
		PATH="$${PATH}:${LOCALBASE}/bin"
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
CXXFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include -ftemplate-depth-64
CONFIGURE_ARGS=	--with-unicode

USE_WX=		2.8
WX_UNICODE=	yes
WX_COMPS=	wx
WX_CONF_ARGS=	relative

PLIST_FILES=	bin/panoglview

BROKEN_powerpc=		Does not configure on powerpc

.include <bsd.port.mk>

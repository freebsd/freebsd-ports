# Created by: argv[0] (Iouri V. Ivliev)
# $FreeBSD$

PORTNAME=	panoglview
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Panorama viewer using OpenGL

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WX_CONFIG_NAME=${WX_CONFIG} \
		PATH="$${PATH}:${LOCALBASE}/bin"
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
CXXFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include -ftemplate-depth-64
USE_GMAKE=	yes

USE_WX=		2.6+
WX_COMPS=	wx
WX_CONF_ARGS=	relative

PLIST_FILES=	bin/panoglview

OPTIONS_DEFINE=	UNICODE
OPTIONS_DEFAULT=	UNICODE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

.if ${PORT_OPTIONS:MUNICODE}
WX_UNICODE=	yes
CONFIGURE_ARGS+=	--with-unicode
.else
.undef WX_UNICODE
CONFIGURE_ARGS+=	--without-unicode
.endif

.include <bsd.port.mk>

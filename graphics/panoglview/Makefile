# New ports collection makefile for:   panoglview
# Date created:        Sat Apr 28 07:59:00 UTC 2007
# Whom:                argv[0] (Iouri V. Ivliev)
#
# $FreeBSD$
#

PORTNAME=	panoglview
PORTVERSION=	0.2.2
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

OPTIONS=	UNICODE	"Use UNICODE version of the wxgtk"	on

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

.if defined(WITH_UNICODE)
WX_UNICODE=	yes
CONFIGURE_ARGS+=	--with-unicode
.else
.undef WX_UNICODE
CONFIGURE_ARGS+=	--without-unicode
.endif

.include <bsd.port.post.mk>

# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	reallyslick
PORTVERSION=	0.9.1
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF/rss-glx/rss-glx/${PORTVERSION}
DISTNAME=	rss-glx_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL screensaver collection

LIB_DEPENDS=	libMagickWand.so:${PORTSDIR}/graphics/ImageMagick \
		libGLC.so:${PORTSDIR}/graphics/quesoglc

USE_GL=		glut
USES=		gmake pathfix tar:bzip2 libtool
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXext

OPTIONS_DEFINE=	FREEALUT GLEW

FREEALUT_DESC=	Enable freealut support
FREEALUT_CONFIGURE_ENABLE=	sound
FREEALUT_USES=	openal:alut

GLEW_DESC=	Enable GLEW support
GLEW_USE=	GL=glew

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MGLEW}
CONFIGURE_ENV+=	ac_cv_header_GL_glew_h=no
.endif

.include <bsd.port.mk>

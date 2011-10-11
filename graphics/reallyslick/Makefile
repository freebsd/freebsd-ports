# New ports collection makefile for:	reallyslick
# Date created:				24 Nov 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	reallyslick
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF/rss-glx/rss-glx/${PORTVERSION}
DISTNAME=	rss-glx_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL screensaver collection

LIB_DEPENDS=	MagickWand.5:${PORTSDIR}/graphics/ImageMagick \
		GLC.0:${PORTSDIR}/graphics/quesoglc

OPTIONS=	FREEALUT "Enable freealut support" off \
		GLEW "Enable GLEW support" off

USE_BZIP2=	yes
USE_GL=		glut
USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		biof.1 busyspheres.1 colorfire.1 cyclone.1 drempels.1 \
		euphoria.1 feedback.1 fieldlines.1 flocks.1 flux.1 \
		helios.1 hufo_smoke.1 hufo_tunnel.1 hyperspace.1 lattice.1 \
		lorenz.1 matrixview.1 pixelcity.1 plasma.1 skyrocket.1 \
		solarwinds.1 spirographx.1 sundancer2.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_FREEALUT)
USE_OPENAL=	alut
.else
CONFIGURE_ARGS+=	--disable-sound
.endif

.if defined(WITH_GLEW)
USE_GL+=	glew
.else
CONFIGURE_ENV+=	ac_cv_header_GL_glew_h=no
.endif

.include <bsd.port.post.mk>

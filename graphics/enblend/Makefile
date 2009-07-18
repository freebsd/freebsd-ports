# New ports collection makefile for:	enblend
# Date created:			19 september 2004
# Whom:				cartola@openit.com.br
#
# $FreeBSD$
#

PORTNAME=	enblend
PORTVERSION=	3.1.r20080615
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/enblend

MAINTAINER=	vd@FreeBSD.org
COMMENT=	A tool for image blending with multiresolution splines

BUILD_DEPENDS=	${LOCALBASE}/include/boost/pool/pool.hpp:${PORTSDIR}/devel/boost \
		OpenEXR>=1.0:${PORTSDIR}/graphics/OpenEXR
LIB_DEPENDS=	GLEW.1:${PORTSDIR}/graphics/glew \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		xmi.1:${PORTSDIR}/graphics/plotutils \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	OpenEXR>=1.0:${PORTSDIR}/graphics/OpenEXR

USE_BZIP2=	yes

USE_AUTOTOOLS=	automake:110:env autoconf:262:env

# GCC 4.2 has some problems, see
# http://groups.google.com/group/hugin-ptx/browse_thread/thread/725b1581c9889e37/50abe3387d61541a#50abe3387d61541a
USE_GCC=	4.3+
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		enblend.1 enfuse.1
PLIST_FILES=	bin/enblend bin/enfuse

# run autotools
pre-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.cvs

.include <bsd.port.mk>

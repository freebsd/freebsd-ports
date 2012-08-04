# New ports collection makefile for:	enblend
# Date created:			19 september 2004
# Whom:				cartola@openit.com.br
#
# $FreeBSD$
#

PORTNAME=	enblend
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enblend/enblend-enfuse/enblend-enfuse-${PORTVERSION}
DISTNAME=	enblend-enfuse-${PORTVERSION}

MAINTAINER=	grog@FreeBSD.org
COMMENT=	A tool for image blending with multiresolution splines

BUILD_DEPENDS=	${LOCALBASE}/include/boost/pool/pool.hpp:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo \
		OpenEXR>=1.0:${PORTSDIR}/graphics/OpenEXR
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		xmi:${PORTSDIR}/graphics/plotutils \
		tiff:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	OpenEXR>=1.0:${PORTSDIR}/graphics/OpenEXR

WRKSRC=		${WRKDIR}/enblend-enfuse-4.0-753b534c819d

USE_AUTOTOOLS=	automake:env autoconf:env
USE_GMAKE=	yes
# We need a newer version of makinfo for this.
# Remove this line when we remove texinfo from the base system.
CONFIGURE_ARGS=	MAKEINFO="${LOCALBASE}/bin/makeinfo"

# GCC 4.2 has some problems, see
# http://groups.google.com/group/hugin-ptx/browse_thread/thread/725b1581c9889e37/50abe3387d61541a#50abe3387d61541a
# Gerald Pfeifer <gerald@pfeifer.com> asked to use 4.4+ instead of 4.3+
USE_GCC=	4.4+
USE_GL=		glew glut
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		enblend.1 enfuse.1
PLIST_FILES=	bin/enblend bin/enfuse

# run autotools
#pre-configure:
#	cd ${WRKSRC} && ${MAKE} -f Makefile.cvs

.include <bsd.port.mk>

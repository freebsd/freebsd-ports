# Created by: cartola@openit.com.br
# $FreeBSD$

PORTNAME=	enblend
PORTVERSION=	4.1.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/enblend/enblend-enfuse/enblend-enfuse-${PORTVERSION:R}
DISTNAME=	enblend-enfuse-${PORTVERSION}

MAINTAINER=	grog@FreeBSD.org
COMMENT=	Tool for image blending with multiresolution splines

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo \
		OpenEXR>=1.0:${PORTSDIR}/graphics/OpenEXR
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms2:${PORTSDIR}/graphics/lcms2 \
		xmi:${PORTSDIR}/graphics/plotutils \
		tiff:${PORTSDIR}/graphics/tiff \
		boost_filesystem:${PORTSDIR}/devel/boost-libs \
		vigraimpex:${PORTSDIR}/graphics/vigra \
		gsl:${PORTSDIR}/math/gsl
RUN_DEPENDS=	OpenEXR>=1.0:${PORTSDIR}/graphics/OpenEXR

USE_AUTOTOOLS=	automake:env autoconf:env
USE_GMAKE=	yes
# We need a newer version of makinfo for this.
# Remove this line when we remove texinfo from the base system.
CONFIGURE_ARGS=	MAKEINFO="${LOCALBASE}/bin/makeinfo"

# GCC 4.2 has some problems, see
# http://groups.google.com/group/hugin-ptx/browse_thread/thread/725b1581c9889e37/50abe3387d61541a#50abe3387d61541a
USE_GCC=	yes
USE_GL=		glew glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	"LIBS=-lboost_system"
CONFIGURE_ARGS+=	--with-boost-filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		enfuse enblend
MAN1=		enblend.1 enfuse.1
PLIST_FILES=	bin/enblend bin/enfuse

NO_STAGE=	yes
post-install:
		${INSTALL_DATA} ${WRKSRC}/doc/*.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>

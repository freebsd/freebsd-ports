# Created by: cartola@openit.com.br
# $FreeBSD$

PORTNAME=	enblend
PORTVERSION=	4.1.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/enblend/enblend-enfuse/enblend-enfuse-${PORTVERSION:R}
DISTNAME=	enblend-enfuse-${PORTVERSION}

MAINTAINER=	grog@FreeBSD.org
COMMENT=	Tool for image blending with multiresolution splines

BUILD_DEPENDS=	help2man:misc/help2man \
		${LOCALBASE}/bin/makeinfo:print/texinfo \
		OpenEXR>=1.0:graphics/OpenEXR
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libtiff.so:graphics/tiff \
		libboost_filesystem.so:devel/boost-libs \
		libvigraimpex.so:graphics/vigra \
		libgsl.so:math/gsl
RUN_DEPENDS=	OpenEXR>=1.0:graphics/OpenEXR

USE_AUTOTOOLS=	automake:env autoconf:env
USES=		compiler:features gmake jpeg makeinfo
# We need a newer version of makeinfo for this.
# Remove this line when we remove texinfo from the base system.
CONFIGURE_ARGS=	MAKEINFO="${LOCALBASE}/bin/makeinfo"

USE_GL=		glew glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-boost-filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lboost_system

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc
# GCC 4.2 has some problems, see
# http://groups.google.com/group/hugin-ptx/browse_thread/thread/725b1581c9889e37/50abe3387d61541a#50abe3387d61541a
# Clang, on 10.0-RELEASE is fine.
USE_GCC=	yes
.else
CXXFLAGS+=	-Wno-c++11-extensions
.endif

INFO=		enfuse enblend
PLIST_FILES=	bin/enblend bin/enfuse man/man1/enblend.1.gz man/man1/enfuse.1.gz

post-install:
		${INSTALL_DATA} ${WRKSRC}/doc/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>

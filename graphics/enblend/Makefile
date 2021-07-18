# Created by: cartola@openit.com.br

PORTNAME=	enblend
PORTVERSION=	4.2
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	SF/enblend/enblend-enfuse/enblend-enfuse-${PORTVERSION}
DISTNAME=	enblend-enfuse-${PORTVERSION}

MAINTAINER=	grog@FreeBSD.org
COMMENT=	Tool for image blending with multiresolution splines

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man \
		${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libtiff.so:graphics/tiff \
		libvigraimpex.so:graphics/vigra \
		libgsl.so:math/gsl \
		libOpenEXR.so:graphics/openexr \
		libpng.so:graphics/png

USES=		compiler:features gmake jpeg localbase pkgconfig

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/enblend bin/enfuse man/man1/enblend.1.gz man/man1/enfuse.1.gz
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc
# GCC 4.2 has some problems, see
# http://groups.google.com/group/hugin-ptx/browse_thread/thread/725b1581c9889e37/50abe3387d61541a#50abe3387d61541a
# Clang, on 10.0-RELEASE is fine.
USE_GCC=	yes
.else
CXXFLAGS+=	-Wno-c++11-extensions
.endif

post-patch:
	@${REINPLACE_CMD} -e '/a LaTeX/d' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

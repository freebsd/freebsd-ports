PORTNAME=	lasi
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source
DISTNAME=	libLASi-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C++ stream output interface for creating Postscript documents
WWW=		https://www.unifont.org/lasi/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libltdl.so:devel/libltdl

USES=		cmake compiler:c++11-lang gnome pathfix pkgconfig
USE_CXXSTD=	c++14
PATHFIX_CMAKELISTSTXT=	pkg-config.cmake
USE_GNOME=	pango
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_DATADIR:PATH=${DATADIR}

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen
DOCS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-cmake+modules+lasi.cmake

pre-install-EXAMPLES-off:
	@${REINPLACE_CMD} 's/^\(add_subdirectory(examples)\)/#\1/' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/libLASi.so.2.0.0 \
		${STAGEDIR}${PREFIX}/lib/libLASi.so.2

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MV} ${STAGEDIR}${DATADIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
	@${RMDIR} ${STAGEDIR}${DATADIR}/examples

.include <bsd.port.mk>

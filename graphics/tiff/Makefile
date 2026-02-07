PORTNAME=	tiff
DISTVERSION=	4.7.1
CATEGORIES=	graphics
MASTER_SITES=	https://download.osgeo.org/libtiff/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Tools and library routines for working with TIFF images
WWW=		http://www.simplesystems.org/libtiff/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate \
		libjbig.so:graphics/jbigkit \
		libLerc.so:graphics/lerc \
		libzstd.so:archivers/zstd

USES=		cmake:testing cpe jpeg pathfix pkgconfig tar:xz
CPE_PRODUCT=	libtiff
PATHFIX_CMAKELISTSTXT=	PkgConfig.cmake
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/tiff-${DISTVERSION}

CMAKE_TESTING_ON=	tiff-tests

CMAKE_OFF=	tiff-docs \
		tiff-tests
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_GLUT \
		CMAKE_DISABLE_FIND_PACKAGE_OpenGL \
		CMAKE_DISABLE_FIND_PACKAGE_WebP

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man-prebuilt/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man-prebuilt/*.3tiff ${STAGEDIR}${PREFIX}/share/man/man3

post-install-DOCS-on:
	(cd ${WRKSRC}/doc/html-prebuilt && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/manual)
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LICENSE.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/RELEASE-DATE ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/VERSION ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

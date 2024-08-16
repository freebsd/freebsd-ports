PORTNAME=	dcmtk
DISTVERSIONPREFIX=	${PORTNAME:tu}-
DISTVERSION=	3.6.8
CATEGORIES=	graphics devel

PATCH_SITES=	https://github.com/DCMTK/${PORTNAME}/commit/
PATCHFILES+=	c29bebcd19bb963d72dcd00ca8745f60f6b9a39e.patch:-p1 # fix compilation with clang 19, gcc 15

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DICOM ToolKit, libraries and applications for DICOM/MEDICOM standard
WWW=		https://dcmtk.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang cmake cpe gnome jpeg ssl
CPE_VENDOR=	offis
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	DCMTK_WITH_DOXYGEN

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

ETCDIR=		${PREFIX}/etc/${PORTNAME}-${PORTVERSION}
DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

TEST_TARGET=	test test-exhaustive

PORTSCOUT=	limit:^.*[0-9].*$$ # prevent tags like latest

.include <bsd.port.pre.mk>

.if ${ARCH:Mpowerpc*} && ${COMPILER_VERSION} == 140
LLVM_VER=	15
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CC=		${LOCALBASE}/bin/clang${LLVM_VER}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VER}
.endif

.include <bsd.port.post.mk>

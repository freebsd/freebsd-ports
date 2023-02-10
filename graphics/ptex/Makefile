PORTNAME=	ptex
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES?=	graphics

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Per face texture library
WWW=		https://ptex.us

LICENSE=	BSD3CLAUSE

USES=		cmake:insource compiler:c++11-lang cpe pkgconfig
CPE_VENDOR=	disneyanimation
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wdas

# yes really, the release tarbal doesn't know what version it is
CMAKE_ARGS+=	-DPTEX_VER:STRING=${DISTVERSION} \
		-DCMAKE_INSTALL_INCLUDEDIR:STRING=${LOCALBASE}/include/ptex \
		-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR}

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	PTEX_BUILD_DOCS

pre-build-DOCS-on:
	@(cd ${WRKSRC}/src/doc && doxygen -u Doxyfile)

.include <bsd.port.mk>

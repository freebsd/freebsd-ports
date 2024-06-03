PORTNAME=	ptex
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/wdas/${PORTNAME}/commit/
PATCHFILES+=	8ff5c3e2cf2d2689ca09fc258da2173bfd57cf84.patch:-p1 # fix builds for FreeBSD

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Per face texture library
WWW=		https://ptex.us

LICENSE=	BSD3CLAUSE

USES=		cmake:insource compiler:c++11-lang cpe pkgconfig
CPE_VENDOR=	disneyanimation
USE_GITHUB=	yes
GH_ACCOUNT=	wdas
USE_LDCONFIG=	yes

# yes really, the release tarbal doesn't know what version it is
CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR} \
		-DCMAKE_INSTALL_INCLUDEDIR:STRING=${LOCALBASE}/include/ptex \
		-DPTEX_VER:STRING=${DISTVERSION}

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	PTEX_BUILD_DOCS

pre-build-DOCS-on:
	@(cd ${WRKSRC}/src/doc && doxygen -u Doxyfile)

.include <bsd.port.mk>

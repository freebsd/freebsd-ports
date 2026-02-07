PORTNAME=	lib3mf
DISTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/3MFConsortium/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source-with-submodules

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Implementation of the 3D Manufacturing Format file standard
WWW=		http://3mf.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fast_float>0:math/fast_float
LIB_DEPENDS=	libzip.so:archivers/libzip
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		compiler:c++17-lang cmake:testing localbase:ldflags pathfix \
		pkgconfig python
USE_LDCONFIG=	yes

EXTRACT_SUFX=	.zip
EXTRACT_AFTER_ARGS=	--exclude Libraries/fast_float \
			--exclude Libraries/googletest \
			--exclude Libraries/libressl \
			--exclude Libraries/libzip \
			--exclude Libraries/zlib \
			--exclude submodules/fast_float \
			--exclude submodules/googletest \
			--exclude submodules/libzip \
			--exclude submodules/zlib \
			--no-same-owner --no-same-permissions

NO_WRKSUBDIR=	yes

CXXFLAGS+=	-I${LOCALBASE}/include/fast_float

.if make(test)
LDFLAGS+=	-lgmock -lgtest
.endif

CMAKE_TESTING_ON=	LIB3MF_TESTS

CMAKE_OFF=	USE_INCLUDED_LIBZIP \
		USE_INCLUDED_ZLIB \
		USE_INCLUDED_SSL \
		LIB3MF_TESTS

.include <bsd.port.mk>

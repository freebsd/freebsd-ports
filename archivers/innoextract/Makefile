PORTNAME=	innoextract
DISTVERSION=	1.9-11
DISTVERSIONSUFFIX=	-g264c2fe
CATEGORIES=	archivers

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Program to extract Inno Setup files
WWW=		https://constexpr.org/innoextract/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang iconv
USE_GITHUB=	yes
GH_ACCOUNT=	dscharrer
CMAKE_ON=	Boost_USE_STATIC_LIBS

PLIST_FILES=	bin/innoextract \
		share/man/man1/innoextract.1.gz

.include <bsd.port.mk>

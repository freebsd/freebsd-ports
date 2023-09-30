PORTNAME=	innoextract
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://constexpr.org/innoextract/files/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Program to extract Inno Setup files
WWW=		https://constexpr.org/innoextract/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang iconv
CMAKE_ON=	Boost_USE_STATIC_LIBS

PLIST_FILES=	bin/innoextract \
		share/man/man1/innoextract.1.gz

.include <bsd.port.mk>

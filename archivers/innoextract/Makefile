# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	innoextract
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	http://constexpr.org/innoextract/files/

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Program to extract Inno Setup files

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=		Does not build: undefined reference to std::ctype<char>::_M_widen_init()

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs

USES=		cmake compiler:c++11-lang iconv

PLIST_FILES=	bin/innoextract \
		man/man1/innoextract.1.gz

.include <bsd.port.mk>

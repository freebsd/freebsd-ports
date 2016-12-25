# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	innoextract
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://constexpr.org/innoextract/files/

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Program to extract Inno Setup files

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs

USES=		cmake iconv

PLIST_FILES=	bin/innoextract \
		man/man1/innoextract.1.gz

BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build: undefined reference to std::ctype<char>::_M_widen_init()

.include <bsd.port.mk>

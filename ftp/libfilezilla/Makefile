# $FreeBSD$

PORTNAME=	libfilezilla
PORTVERSION=	0.5.1
CATEGORIES=	ftp
MASTER_SITES=	SF/filezilla/${PORTNAME}/${PORTVERSION}

MAINTAINER=	matthew@reztek.cz
COMMENT=	C++ library for building platform-independent programs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

BROKEN_FreeBSD_9=	requires C++14 complier, 9.x lacks C++11 standard library

USES=		compiler:c++14-lang gmake iconv:wchar_t libtool localbase pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	libfilezilla
PORTVERSION=	0.9.0
CATEGORIES=	ftp
MASTER_SITES=	http://download.filezilla-project.org/${PORTNAME}/

MAINTAINER=	matthew@reztek.cz
COMMENT=	C++ library for building platform-independent programs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

USES=		compiler:c++14-lang gmake iconv:wchar_t libtool localbase pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

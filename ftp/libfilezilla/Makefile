# $FreeBSD$

PORTNAME=	libfilezilla
PORTVERSION=	0.15.1
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	https://download.filezilla-project.org/${PORTNAME}/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	C++ library for building platform-independent programs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnettle.so:security/nettle

USES=		compiler:c++14-lang gmake iconv:wchar_t libtool localbase \
		pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

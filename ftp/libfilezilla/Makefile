# $FreeBSD$

PORTNAME=	libfilezilla
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://download.filezilla-project.org/${PORTNAME}/

MAINTAINER=	rezny@FreeBSD.org
COMMENT=	C++ library for building platform-independent programs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++14-lang gmake iconv:wchar_t libtool localbase \
		pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

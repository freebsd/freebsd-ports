PORTNAME=	libdynamite
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/Dynamite/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decompress data compressed with PKWARE Data Compression Library
WWW=		https://synce.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

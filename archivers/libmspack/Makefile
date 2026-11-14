PORTNAME=	libmspack
PORTVERSION=	0.12alpha
CATEGORIES=	archivers
MASTER_SITES=	https://www.cabextract.org.uk/libmspack/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for Microsoft compression formats
WWW=		https://www.cabextract.org.uk/libmspack/ \
		https://github.com/kyz/libmspack/tree/master/libmspack

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cpe libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPE_VENDOR=	kyzer

.include <bsd.port.mk>

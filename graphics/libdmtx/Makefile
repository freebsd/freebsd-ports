PORTNAME=	libdmtx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library for reading and writing Data Matrix barcodes
WWW=		https://libdmtx.sourceforge.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pathfix autoreconf libtool

USE_GITHUB=	yes
GH_ACCOUNT=	dmtx

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

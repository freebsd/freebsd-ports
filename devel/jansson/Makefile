# Created by: vanilla@
# $FreeBSD$

PORTNAME=	jansson
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.digip.org/jansson/releases/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for encoding, decoding, and manipulating JSON data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe pathfix pkgconfig gmake tar:bzip2 libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPE_VENDOR=	jansson_project
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>

# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libbrotli
PORTVERSION=	1.0
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	6
CATEGORIES=	devel archivers

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for generic-purpose lossless compression algorithm

LICENSE=	MIT

BROTLI_VERSION=	v0.4.0

USE_GITHUB=	yes
GH_ACCOUNT=	bagder google:brotli
GH_PROJECT=	brotli:brotli
GH_TAGNAME=	${BROTLI_VERSION}:brotli
GH_SUBDIR=	brotli:brotli

USES=		pkgconfig autoreconf libtool compiler:c++0x pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>

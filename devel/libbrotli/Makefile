# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libbrotli
PORTVERSION=	${BROTLI_VERSION}
PORTREVISION=	3
CATEGORIES=	devel archivers

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for generic-purpose lossless compression algorithm

LICENSE=	MIT

LIBBROTLI_VERSION=	347bc0f
BROTLI_VERSION=		0.3.0

USE_GITHUB=	yes
GH_ACCOUNT=	bagder google:brotli
GH_PROJECT=	brotli:brotli
GH_TAGNAME=	${LIBBROTLI_VERSION} v${BROTLI_VERSION}:brotli

USES=		pkgconfig autoreconf libtool compiler:c++0x
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

post-extract:
	${RMDIR} ${WRKSRC}/brotli && ${MV} ${WRKDIR}/brotli-${BROTLI_VERSION} ${WRKSRC}/brotli

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>

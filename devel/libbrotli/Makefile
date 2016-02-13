# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libbrotli
PORTVERSION=	${BROTLI_VERSION}
PORTREVISION=	1
CATEGORIES=	devel archivers

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for generic-purpose lossless compression algorithm

LICENSE=	MIT

LIBBROTLI_VERSION=	53d53e8
BROTLI_VERSION=		0.3.0

USE_GITHUB=	yes
GH_ACCOUNT=	bagder google:brotli
GH_PROJECT=	brotli:brotli
GH_TAGNAME=	${LIBBROTLI_VERSION} v${BROTLI_VERSION}:brotli

USES=		pkgconfig autoreconf libtool compiler:c++0x
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

pre-configure:
	${RMDIR} ${WRKSRC}/brotli && ${MV} ${WRKDIR}/brotli-${BROTLI_VERSION} ${WRKSRC}/brotli
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>

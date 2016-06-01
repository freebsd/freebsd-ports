# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libbrotli
PORTVERSION=	1.0
PORTREVISION=	2
MASTER_SITES=	https://github.com/bagder/libbrotli/archive/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
CATEGORIES=	devel archivers

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for generic-purpose lossless compression algorithm

LICENSE=	MIT

BROTLI_VERSION=	3a77ebe

USE_GITHUB=	nodefault
GH_ACCOUNT=	google:brotli
GH_PROJECT=	brotli:brotli
GH_TAGNAME=	${BROTLI_VERSION}:brotli

USES=		pkgconfig autoreconf libtool compiler:c++0x
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}

post-extract:
	${RMDIR} ${WRKSRC}/brotli && ${MV} ${WRKSRC_brotli} ${WRKSRC}/brotli

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>

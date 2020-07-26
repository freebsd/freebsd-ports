# $FreeBSD$

PORTNAME=	tar-stream-chunker
PORTVERSION=	1.0.6
CATEGORIES=	archivers

MAINTAINER=	igor.ostapenko@pm.me
COMMENT=	Splits stdin of unknown size onto chunks packed as a TAR to stdout

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ihoro

PLIST_FILES=	bin/tar_stream_chunker

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tar_stream_chunker

.include <bsd.port.mk>

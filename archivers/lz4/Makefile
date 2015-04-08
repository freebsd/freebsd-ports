# Created by: Alexey Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	r101
CATEGORIES=	archivers
MASTER_SITES=	https://dl.dropboxusercontent.com/u/59565338/LZ4/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Fast compressor using LZ4 algorithm

USES=		gmake
ALL_TARGET=	lz4c

DEPRECATED=	Superseded by archivers/liblz4; use that instead
EXPIRATION_DATE=2015-05-08

CONFLICTS=	liblz4-*

PLIST_FILES=	bin/lz4c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lz4c.exe ${STAGEDIR}${PREFIX}/bin/lz4c

.include <bsd.port.mk>

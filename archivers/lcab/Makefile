# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcab
DISTVERSION=	1.0b12
CATEGORIES=	archivers
MASTER_SITES=	ftp://ohnopublishing.net/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Microsoft .CABinet file creator

LICENSE=	GPLv2

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/lcab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lcab ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>

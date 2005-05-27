# New ports collection makefile for:	LCAB
# Date created:				27 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lcab
DISTVERSION=	1.0b11
CATEGORIES=	archivers
MASTER_SITES=	http://www.geekshop.be/rien/lcab/files/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Microsoft .CABinet file creator

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/lcab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lcab ${PREFIX}/bin

.include <bsd.port.mk>

# New ports collection makefile for:    ha
# Date created:         24 Jan 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	ha
PORTVERSION=	0.999b
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
DISTNAME=	ha0999
EXTRACT_SUFX=	.tgz

MAINTAINER=	ache@FreeBSD.org

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.nix
MAKE_FLAGS=	CC=cc -f
ALL_TARGET=	ha
USE_GMAKE=	yes

do-install:
	cd ${WRKSRC}; ${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ha ${PREFIX}/bin

.include <bsd.port.mk>

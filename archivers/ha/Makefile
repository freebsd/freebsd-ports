# New ports collection makefile for:    ha
# Date created:         24 Jan 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	ha
PORTVERSION=	0.999b
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
DISTNAME=	ha0999
EXTRACT_SUFX=	.tgz

MAINTAINER=	ache@FreeBSD.org
COMMENT=	The HA archiver using the HSC compression method

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ha
MAKEFILE=	makefile.nix
ALL_TARGET=	ha
USE_GMAKE=	yes
USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/c/hsc.c ${WRKSRC}/c/cpy.c \
		${WRKSRC}/c/asc.c

do-install:
	cd ${WRKSRC}; ${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ha ${PREFIX}/bin

.include <bsd.port.mk>

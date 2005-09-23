# New ports collection makefile for:	mph
# Date created:				2005/9/22
# Whom:					Chuck Swiger <chuck@pkix.net>
#
# $FreeBSD$
#

PORTNAME=	mph
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c

MAINTAINER=	chuck@pkix.net
COMMENT=	Minimal perfect hashing code generator

BIN_FILES=	emitc mph mphm
PLIST_FILES=	bin/emitc bin/mph bin/mphm

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin/
.endfor

.include <bsd.port.mk>

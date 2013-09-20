# Created by: Chuck Swiger <chuck@pkix.net>
# $FreeBSD$

PORTNAME=	mph
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c

MAINTAINER=	chuck@pkix.net
COMMENT=	Minimal perfect hashing code generator

BIN_FILES=	emitc mph mphm
PLIST_FILES=	bin/emitc bin/mph bin/mphm

NO_STAGE=	yes
do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin/
.endfor

.include <bsd.port.mk>

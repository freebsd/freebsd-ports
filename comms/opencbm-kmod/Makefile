# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	opencbm-kmod
PORTVERSION=	${OCBM_VERSION}
CATEGORIES=	comms archivers

MAINTAINER=	felix@palmen-it.de
COMMENT=	OpenCBM driver module for parallel-port X[MA]-1541 cables

LICENSE=	GPLv2+

USES=	kmod uidfix

WRKSRC_SUBDIR=	opencbm/sys/freebsd

post-install:
	${INSTALL_MAN} ${FILESDIR}/opencbm.4 ${STAGEDIR}${PREFIX}/man/man4

.include "../opencbm/Makefile.inc"

.include <bsd.port.mk>

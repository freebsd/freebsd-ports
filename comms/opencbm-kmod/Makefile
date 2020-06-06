# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	opencbm-kmod
PORTVERSION=	${OCBM_VERSION}
CATEGORIES=	comms archivers

PATCHFILES=	ca4c06e7430caf3b2296d4e1e00051fff015fc53.diff \
		073b833772e4325c7f680d6aeb81bc11844f03ca.diff \
		3e967551e200d0c03aa4898e482626a7510acd21.diff

MAINTAINER=	felix@palmen-it.de
COMMENT=	OpenCBM driver module for parallel-port X[MA]-1541 cables

LICENSE=	GPLv2+

USES=	kmod uidfix

WRKSRC_SUBDIR=	opencbm/sys/freebsd

post-install:
	${INSTALL_MAN} ${FILESDIR}/opencbm.4 ${STAGEDIR}${PREFIX}/man/man4

.include "../opencbm/Makefile.inc"

.include <bsd.port.mk>

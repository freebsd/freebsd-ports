PORTNAME=	opencbm-kmod
PORTVERSION=	${OCBM_VERSION}
PORTREVISION=	2
CATEGORIES=	comms archivers

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	OpenCBM driver module for parallel-port X[MA]-1541 cables
WWW=		http://opencbm.sourceforge.net/

LICENSE=	GPLv2+

USES=	kmod uidfix

WRKSRC_SUBDIR=	opencbm/sys/freebsd

.include "../opencbm/Makefile.inc"

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man/man

.include <bsd.port.mk>

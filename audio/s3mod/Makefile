# New ports collection makefile for:    s3mod
# Version required:     1.09
# Date created:         9 March 1995
# Whom:                 ugen
#
# $FreeBSD$
#

DISTNAME=	s3mod-v1.09
PKGNAME=	s3mod-1.09
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=	ugen@FreeBSD.org

ALL_TARGET=	freebsd

pre-patch:
	@${CP} ${WRKSRC}/DspDrivers/linux_dsp.c ${WRKSRC}/dsp.c

post-install:
	@strip ${PREFIX}/bin/s3mod

.include <bsd.port.mk>

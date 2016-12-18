# Created by: ugen
# $FreeBSD$

PORTNAME=	s3mod
PORTVERSION=	1.09
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MOD/S3M player

USES=		alias
ALL_TARGET=	freebsd
PLIST_FILES=	bin/s3mod

post-extract:
	@${CP} ${WRKSRC}/DspDrivers/linux_dsp.c ${WRKSRC}/dsp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/s3mod ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

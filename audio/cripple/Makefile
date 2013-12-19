# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cripple
PORTVERSION=	0.06b
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.vortex.prodigynet.co.uk/${PORTNAME}/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Command line CD ripper/encoder wrapper with cddb support

NO_STAGE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

LIB_DEPENDS+=	libcdio.so:${PORTSDIR}/sysutils/libcdio
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame\
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		cdda2wav:${PORTSDIR}/sysutils/cdrtools

MAN1=		cripple.1

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

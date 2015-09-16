# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cripple
PORTVERSION=	0.06b
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://www.vortex.prodigynet.co.uk/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line CD ripper/encoder wrapper with cddb support

BROKEN=		Fails to fetch
USES=		tar:bzip2
GNU_CONFIGURE=	yes

LIB_DEPENDS+=	libcdio.so:${PORTSDIR}/sysutils/libcdio
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame\
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		cdda2wav:${PORTSDIR}/sysutils/cdrtools

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/cripple.1.gz

.include <bsd.port.mk>

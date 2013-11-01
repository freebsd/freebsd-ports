# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	midipp
PORTVERSION=	1.2.3
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	MIDI playback, recording, and live performance tool

LICENSE=	BSD

BUILD_DEPENDS=	libumidi>=2.0.9:${PORTSDIR}/audio/libumidi
LIB_DEPENDS=	libumidi20.so:${PORTSDIR}/audio/libumidi

USE_BZIP2=	yes
NO_STAGE=	yes

USE_QT4=	gui qmake_build moc_build rcc_build network

QMAKE_MIDIPP=	${QMAKE} -unix PREFIX=${PREFIX} -o

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE_MIDIPP} Makefile ${PORTNAME}.pro

.include <bsd.port.mk>

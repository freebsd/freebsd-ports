# Ports collection makefile for: midipp
# Date created: 21 June 2011
# Whom:		Hans Petter Selasky <hselasky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	midipp
PORTVERSION=	1.0.14
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A MIDI playback, recording, and live performance tool

BUILD_DEPENDS=	libumidi>=2.0.2:${PORTSDIR}/audio/libumidi

LIB_DEPENDS=	umidi20.1:${PORTSDIR}/audio/libumidi

LICENSE=	BSD
USE_BZIP2=	yes

USE_QT4=	gui qmake_build moc_build rcc_build

MAKE_JOBS_SAFE=	yes

QMAKE_MIDIPP=	${QMAKE} -unix PREFIX=${PREFIX} -o

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE_MIDIPP} Makefile ${PORTNAME}.pro

.include <bsd.port.post.mk>

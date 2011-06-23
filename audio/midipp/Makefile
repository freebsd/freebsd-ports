# Ports collection makefile for: midipp
# Date created: 21 June 2011
# Whom:		Hans Petter Selasky <hselasky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	midipp
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A MIDI playback, recording and live performance tool

LIB_DEPENDS=	umidi20.1:${PORTSDIR}/audio/libumidi

LICENSE=	BSD
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc
QMAKE_ARGS=	PREFIX=${PREFIX} ${PORTNAME}.pro
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>

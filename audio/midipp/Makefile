# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	midipp
PORTVERSION=	1.3.3
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	MIDI playback, recording, and live performance tool

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libumidi>=2.0.13:audio/libumidi
LIB_DEPENDS=	libumidi20.so:audio/libumidi

USES=		qmake tar:bzip2

_USE_QT4=	corelib gui moc_build rcc_build network
_USE_QT5=	core gui network widgets \
                printsupport buildtools_build

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

TOOLKIT_DESC=	Qt toolkit
QT4_USE=	${_USE_QT4:S/^/QT4=/}
QT5_USE=	${_USE_QT5:S/^/QT5=/} GL=gl

.include <bsd.port.mk>

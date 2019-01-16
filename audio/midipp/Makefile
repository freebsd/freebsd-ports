# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	midipp
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	MIDI playback, recording, and live performance tool

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libumidi>=2.0.14:audio/libumidi
LIB_DEPENDS=	libumidi20.so:audio/libumidi

USES=		qmake tar:bzip2

_USE_QT4=	corelib gui moc_build network rcc_build
_USE_QT5=	buildtools_build core gui network printsupport widgets

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

TOOLKIT_DESC=	Qt toolkit
QT4_USES=	qt:4
QT4_USE=	${_USE_QT4:S/^/QT=/}
QT5_USES=	qt:5
QT5_USE=	${_USE_QT5:S/^/QT=/} GL=gl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.include <bsd.port.mk>

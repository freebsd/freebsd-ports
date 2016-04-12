# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flacon
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file extractor and encoder

LICENSE=	LGPL21

LIB_DEPENDS=	libuchardet.so:textproc/uchardet

USE_GITHUB=	yes

USES=		cmake desktop-file-utils pkgconfig

OPTIONS_DEFINE=	QT5
QT5_DESC=	Build against Qt 5 instead of Qt 4

QT5_CMAKE_ON=	-DUSE_QT5:BOOL=ON
# :ts, would be handy here but is not available in fmake(1)
QT5_USE=	QT5=${_QT5_DEPS},${_QT5_BDEPS:C/,/_build&/g:%=_build}
QT5_USE_OFF=	QT4=${_QT4_DEPS},${_QT4_BDEPS:C/,/_build&/g:%=_build}

_QT4_DEPS=	gui,network
_QT4_BDEPS=	linguisttools,moc,qmake,rcc,uic
_QT5_DEPS=	gui,network,widgets
_QT5_BDEPS=	qmake,buildtools,linguisttools

.include <bsd.port.mk>

# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flacon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file extractor and encoder

LICENSE=	LGPL21

LIB_DEPENDS=	libuchardet.so:${PORTSDIR}/textproc/uchardet

USE_GITHUB=	yes

USES=		cmake pkgconfig
USE_QT4=	gui network \
		linguisttools_build moc_build qmake_build rcc_build uic_build
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

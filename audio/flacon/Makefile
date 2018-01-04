# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flacon
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file extractor and encoder

LICENSE=	LGPL21

LIB_DEPENDS=	libuchardet.so:textproc/uchardet

USES=		cmake desktop-file-utils pkgconfig
USE_GITHUB=	yes
USE_QT5=	buildtools_build concurrent_build qmake_build \
		linguisttools_build core gui network widgets

.include <bsd.port.mk>

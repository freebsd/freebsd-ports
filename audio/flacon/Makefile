# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flacon
PORTVERSION=	5.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file extractor and encoder

LICENSE=	LGPL21+

LIB_DEPENDS=	libuchardet.so:textproc/uchardet

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		buildtools_build concurrent_build qmake_build \
		linguisttools_build core gui network widgets

.include <bsd.port.mk>

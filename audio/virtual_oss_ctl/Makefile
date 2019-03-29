# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss_ctl
PORTVERSION=	1.2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Grapical control panel for the virtual OSS daemon

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	virtual_oss:audio/virtual_oss
LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core gui widgets

.include <bsd.port.mk>

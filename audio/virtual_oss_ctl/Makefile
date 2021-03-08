# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss_ctl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.8
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Graphical control panel for the virtual OSS daemon

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	virtual_oss>=1.2.6:audio/virtual_oss
LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

GH_TUPLE=	hselasky:virtual_oss:v1.2.8:d/virtual_oss

PLIST_FILES= \
	bin/virtual_oss_ctl \
	share/pixmaps/virtual_oss_ctl.png \
	share/applications/virtual_oss_ctl.desktop

.include <bsd.port.mk>

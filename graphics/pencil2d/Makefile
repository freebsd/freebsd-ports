# $FreeBSD$

PORTNAME=	pencil2d
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2-63
DISTVERSIONSUFFIX=	-gd05fbae0
PORTREVISION=	2
CATEGORIES=	graphics math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy and intuitive tool to make 2D hand-drawn animations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		compiler:c++11-lang desktop-file-utils gl gmake qmake qt:5 \
		shared-mime-info
USE_GITHUB=	yes
USE_QT=		core gui multimedia network svg widgets xml buildtools_build
USE_GL=		gl
GH_PROJECT=	pencil

PLIST_FILES=	bin/pencil2d \
		share/applications/pencil2d.desktop \
		share/bash-completion/completions/pencil2d \
		share/icons/hicolor/256x256/apps/pencil2d.png \
		share/mime/packages/pencil2d.xml \
		share/zsh/site-functions/_pencil2d

.include <bsd.port.mk>

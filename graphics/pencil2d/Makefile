PORTNAME=	pencil2d
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	graphics math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy and intuitive tool to make 2D hand-drawn animations
WWW=		https://www.pencil2d.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		compiler:c++11-lang desktop-file-utils gl gmake qmake qt:5 \
		shared-mime-info
USE_QT=		core gui linguisttools multimedia svg testlib widgets xml xmlpatterns \
		buildtools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_PROJECT=	pencil

QMAKE_ARGS=	NO_TESTS=1

PLIST_FILES=	bin/pencil2d \
		share/applications/org.pencil2d.Pencil2D.desktop \
		share/bash-completion/completions/pencil2d \
		share/icons/hicolor/256x256/apps/org.pencil2d.Pencil2D.png \
		share/metainfo/org.pencil2d.Pencil2D.metainfo.xml \
		share/mime/packages/org.pencil2d.Pencil2D.xml \
		share/zsh/site-functions/_pencil2d

.include <bsd.port.mk>

# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-mediaplayer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	deskutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	Streaming media player from the Lumina Desktop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

RUN_DEPENDS=	gstreamer1-qt5>=0:multimedia/gstreamer1-qt \
		gstreamer1-plugins-gl>=0:graphics/gstreamer1-plugins-gl

USES=		compiler:c++11-lang qmake qt:5 gl
USE_GL=		gl
USE_QT=		buildtools_build core concurrent gui \
		multimedia network svg widgets x11extras
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

NLS_USE=	qt=linguist_build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

.include <bsd.port.mk>

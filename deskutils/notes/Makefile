PORTNAME=	notes
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Beautiful and powerful note-taking application
WWW=		https://www.get-notes.com/

LICENSE=	MPL20

USES=		cmake qt:5 xorg
USE_QT=		buildtools:build qmake:build testlib:build \
		concurrent core gui network sql widgets
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	nuttyartist b00f:qas pbek:qmdte
GH_PROJECT=	qautostart:qas qmarkdowntextedit:qmdte
GH_TAGNAME=	efdb2e5:qas b85b0f1:qmdte
GH_SUBDIR=	3rdParty/qautostart:qas 3rdParty/qmarkdowntextedit:qmdte

CMAKE_ARGS=	-DUSE_QT_VERSION:STRING=5 -DUPDATE_CHECKER:BOOL=OFF

.include <bsd.port.mk>

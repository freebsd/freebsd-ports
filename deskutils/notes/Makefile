PORTNAME=	notes
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Beautiful and powerful note-taking application
WWW=		https://www.notes-foss.com/

LICENSE=	MPL20

USES=		cmake qt:5 xorg
USE_QT=		buildtools:build qmake:build testlib:build \
		concurrent core declarative gui network sql widgets \
		quickcontrols2:run sql-sqlite3:run
USE_XORG=	ice sm x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	nuttyartist b00f:qas pbek:qmdte
GH_PROJECT=	qautostart:qas qmarkdowntextedit:qmdte
GH_TAGNAME=	efdb2e5:qas c6420c5:qmdte
GH_SUBDIR=	3rdParty/qautostart:qas 3rdParty/qmarkdowntextedit:qmdte

CMAKE_ARGS=	-DUSE_QT_VERSION:STRING=5 -DUPDATE_CHECKER:BOOL=OFF

.include <bsd.port.mk>

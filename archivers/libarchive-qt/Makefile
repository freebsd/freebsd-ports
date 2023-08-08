PORTNAME=	libarchive-qt
DISTVERSION=	2.0.6
CATEGORIES=	archivers

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Qt based archiving solution with libarchive backend
WWW=		https://gitlab.com/marcusbritanicus/libarchive-qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake qt:5
USE_QT=		buildtools:build core dbus gui network qmake:build widgets
USE_LDCONFIG=	yes
USE_GITLAB=	yes

GL_ACCOUNT=	marcusbritanicus
GL_TAGNAME=	9863127fb8dda7242215c09efbc976193365fee4

.include <bsd.port.mk>

PORTNAME=	libarchive-qt
DISTVERSION=	2.0.8
CATEGORIES=	archivers

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Qt based archiving solution with libarchive backend
WWW=		https://gitlab.com/marcusbritanicus/libarchive-qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake qt:6
USE_QT=		base:run tools:build
USE_LDCONFIG=	yes
USE_GITLAB=	yes

CMAKE_ARGS=	-DUSEQT:String=Qt6

GL_ACCOUNT=	marcusbritanicus
GL_TAGNAME=	9863127fb8dda7242215c09efbc976193365fee4

.include <bsd.port.mk>

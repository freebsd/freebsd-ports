PORTNAME=	qolibri
DISTVERSION=	2.1.4-65
CATEGORIES=	japanese

MAINTAINER=	omatsuda000@gmail.com
COMMENT=	EPWING dictionary viewer
WWW=		https://github.com/ludios/qolibri/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libeb.so:japanese/eb

USES=		cmake compiler:c++17-lang gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	ludios
GH_TAGNAME=	b29f1668d6e56030e531cd4e0e1ec58e370fede9
USE_GL=		opengl
USE_QT=		5compat base declarative multimedia positioning webchannel \
		webengine tools:build

CMAKE_ARGS=	-DQOLIBRI_USE_SYSTEM_EB=true

PLIST_FILES=	bin/qolibri share/applications/qolibri.desktop

.include <bsd.port.mk>

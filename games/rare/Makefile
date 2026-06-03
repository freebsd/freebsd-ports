PORTNAME=	rare
DISTVERSION=	1.12.0
CATEGORIES=	games

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Frontend for legendary
WWW=		https://github.com/RareDevs/Rare

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	legendary>0:games/legendary \
		${PYTHON_PKGNAMEPREFIX}orjson>0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtAwesome>0:x11-fonts/py-QtAwesome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vdf>0:devel/vdf@${PY_FLAVOR}

USES=		desktop-file-utils python

USE_GITHUB=	yes
GH_ACCOUNT=	RareDevs
GH_PROJECT=	Rare

USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/rare.desktop \
		${STAGEDIR}${PREFIX}/share/applications/rare.desktop
	${INSTALL_DATA} ${WRKSRC}/rare/resources/images/Rare.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/rare.png

PLIST_FILES=	share/applications/rare.desktop \
		share/pixmaps/rare.png

.include <bsd.port.mk>

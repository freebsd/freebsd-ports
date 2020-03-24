# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=	unknown-horizons
PORTVERSION=	2019.1
CATEGORIES=	games

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Real time simulation game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/licenses/GPL

BUILD_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fife>0:games/py-fife@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		gettext-tools gnome python:3.5+ shebangfix
USE_GITHUB=	yes
USE_GNOME=	intltool
USE_PYTHON=	autoplist distutils noflavors
SHEBANG_FILES=	run_uh.py
NO_ARCH=	yes

OPTIONS_DEFINE=		ENET NLS
OPTIONS_DEFAULT=	ENET

ENET_DESC=		Multipliplayer support through pyenet
ENET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyenet>0:net/py-pyenet@${PY_FLAVOR}

post-patch-ENET-off:
	@${REINPLACE_CMD} -e 's|import enet|return None|' ${WRKSRC}/horizons/network/__init__.py

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/build.sub_commands.append.*build_i18n/ d' ${WRKSRC}/setup.py

do-build:
	cd ${WRKSRC} && ${SETENV} UH_USER_DIR=${WRKSRC} ${PYTHON_CMD} horizons/engine/generate_atlases.py 2048

post-install-NLS-off:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/locale

.include <bsd.port.mk>

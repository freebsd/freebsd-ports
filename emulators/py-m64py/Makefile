PORTNAME=	m64py
DISTVERSION=	0.2.5.${RELEASE_DATE}
CATEGORIES=	emulators python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	a frontend for Mupen64Plus
WWW=		https://github.com/mupen64plus/mupen64plus-ui-python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSES

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysdl2>0:devel/py-pysdl2@${PY_FLAVOR}
LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysdl2>0:devel/py-pysdl2@${PY_FLAVOR} \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-audio-sdl.so:emulators/mupen64plus-audio-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-input-sdl.so:emulators/mupen64plus-input-sdl \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-video-rice.so:emulators/mupen64plus-video-rice \
		${LOCALBASE}/lib/mupen64plus/mupen64plus-rsp-hle.so:emulators/mupen64plus-rsp-hle

USE_GITHUB=	yes
GH_ACCOUNT=	mupen64plus
GH_PROJECT=	mupen64plus-ui-python
GH_TAGNAME=	90093ce3b353ff0fbe3277eb5d75130debdf0fab

USES=		desktop-file-utils python qt:5 shebangfix
USE_PYTHON=	autoplist distutils
USE_QT=		linguisttools

NO_ARCH=	yes

SHEBANG_FILES=	${WRKSRC}/bin/m64py

RELEASE_DATE=	20231226

post-patch:
	${REINPLACE_CMD} -i "" -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/m64py/platform.py

.include <bsd.port.mk>

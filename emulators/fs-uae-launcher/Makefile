PORTNAME=	fs-uae-launcher
PORTVERSION=	3.1.70
CATEGORIES=	emulators
MASTER_SITES=	https://fs-uae.net/files/FS-UAE-Launcher/Stable/${PORTVERSION}/

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	GUI launcher for the FS-UAE Amiga emulator
WWW=		http://fs-uae.net/launcher

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-lhafile>0:archivers/py-python-lhafile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		gmake gnome pathfix pyqt:5 python tar:xz
USE_PYTHON=	autoplist distutils noflavors
USE_PYQT=	pyqt5

MAKE_ARGS=	prefix=${PREFIX} \
		PYTHON=${PYTHON_CMD}
PYDISTUTILS_INSTALLARGS+=	--install-lib=${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-tools

.include <bsd.port.mk>

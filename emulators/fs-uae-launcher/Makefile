PORTNAME=	fs-uae-launcher
PORTVERSION=	3.0.5
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	https://fs-uae.net/stable/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI launcher for the FS-UAE Amiga emulator
WWW=		http://fs-uae.net/launcher

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-lhafile>0:archivers/py-python-lhafile@${PY_FLAVOR}

USES=		gettext gmake gnome pathfix pyqt:5 python
USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	pyqt5 sip

MAKE_ARGS=	prefix=${PREFIX} PYTHON=${PYTHON_CMD}
PYDISTUTILS_INSTALLARGS+=	--install-lib=${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

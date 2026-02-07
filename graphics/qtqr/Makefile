PORTNAME=	qtqr
DISTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	https://launchpad.net/qr-tools/2.0/${PORTVERSION}/+download/ \
		LOCAL/ehaupt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}_${PORTVERSION}-0~47~ubuntu24.04.1${EXTRACT_SUFX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GUI that makes it easy to create and decode QR codes
WWW=		https://launchpad.net/qr-tools

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zbar-py>=1.0.4:graphics/py-zbar-py@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:5 python shebangfix
USE_PYQT=	pyqt5:run
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	qtqr.py

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qtqr.py \
		${STAGEDIR}${PREFIX}/bin/qtqr
	${INSTALL_DATA} ${WRKSRC}/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/qtqr.png
	${INSTALL_DATA} ${WRKSRC}/debian/qtqr.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/qt5/translations
	${INSTALL_DATA} ${WRKSRC}/*.qm \
		${STAGEDIR}${PREFIX}/share/qt5/translations

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

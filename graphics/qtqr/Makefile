# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qtqr
DISTVERSION=	2.0.bzr39
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	LOCAL/ehaupt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	qr-tools-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GUI that makes it easy to create and decode QR codes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zbar-py>=1.0.4:graphics/py-zbar-py@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:5 python:3.6+ shebangfix
USE_PYQT=	core_run gui_run network_run widgets_run
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	qtqr.py

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qtqr.py ${STAGEDIR}${PREFIX}/bin/qtqr
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/qtqr.png
	${INSTALL_DATA} ${WRKSRC}/qtqr.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/qt5/translations
	${INSTALL_DATA} ${WRKSRC}/*.qm ${STAGEDIR}${PREFIX}/share/qt5/translations

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

PORTNAME=	thonny
PORTVERSION=	4.1.7
CATEGORIES=	devel education python
MASTER_SITES=	PYPI
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	Python IDE for beginners
WWW=		https://thonny.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	pylint:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.18.1:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astroid>=1.4.9:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.16:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0.670:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.4:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=1.5:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asttokens>=2.0:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR}

USES=		python desktop-file-utils
USE_PYTHON=	distutils

NO_ARCH=	yes

ICON_SIZES=	16 22 32 48 64 128 192 256

post-patch:
	@${SED} -i '' -e "s|Exec=/usr/bin/|Exec=|" ${WRKSRC}/packaging/linux/*.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/*.desktop ${STAGEDIR}${PREFIX}/share/applications/
.for sz in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${INSTALL_DATA} ${WRKSRC}/packaging/icons/thonny-${sz}x${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/thonny.png
.endfor

.include <bsd.port.mk>

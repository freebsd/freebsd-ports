PORTNAME=	chirp
DISTVERSION=	20251106
CATEGORIES=	comms hamradio
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DIST_SUBDIR=	chirp

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Free, open-source tool for programming your amateur radio
WWW=		https://chirpmyradio.com/ \
		https://github.com/kk7ds/chirp/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}versioningit>0:devel/py-versioningit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yattag>0:devel/py-yattag@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}suds>0:net/py-suds@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>0:devel/py-lark@${PY_FLAVOR}

USES=		desktop-file-utils gnome python:3.10+ shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	kk7ds
GH_TAGNAME=	0d2703ec

USE_PYTHON=	autoplist distutils pytest
USE_WX=		3.2
WX_COMPS=	python:run

SHEBANG_GLOB=	*.py

NO_ARCH=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch:
	@${ECHO} "Version: ${PORTVERSION}" > ${WRKSRC}/PKG-INFO

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/share && \
		${INSTALL_DATA} ${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps && \
		${INSTALL_DATA} ${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

post-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/share/locale
	@cd ${WRKSRC}/chirp && \
		${COPYTREE_SHARE}  locale ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/share
	@${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/share/locale/Makefile
	@${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/share/locale/check_parameters.py
	@${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/share/locale/README.md

.include <bsd.port.mk>

PORTNAME=	chirp
DISTVERSION=	20260123
CATEGORIES=	comms hamradio
MASTER_SITES=	https://archive.chirpmyradio.com/chirp_next/next-${DISTVERSION}/ \
		LOCAL/vishwin
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Free, open-source tool for programming your amateur radio
WWW=		https://chirpmyradio.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yattag>0:devel/py-yattag@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}suds>0:net/py-suds@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>0:devel/py-lark@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-html>0:devel/py-pytest-html@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8>0:devel/pep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ddt>0:devel/py-ddt@${PY_FLAVOR}

USES=		desktop-file-utils gnome python shebangfix
SHEBANG_GLOB=	*.py

USE_PYTHON=	autoplist pep517 pytest

USE_WX=		3.2
WX_COMPS=	python:run

OPTIONS_DEFINE=	NLS

NO_ARCH=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/chirp\/locale/d' ${WRKSRC}/MANIFEST.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/share && \
		${INSTALL_DATA} ${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps && \
		${INSTALL_DATA} ${PORTNAME}-logo.png ${STAGEDIR}${PREFIX}/share/pixmaps && \
		${INSTALL_DATA} ${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/pixmaps && \
		${INSTALL_DATA} ${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR} && \
		${INSTALL_DATA} *.metainfo.xml ${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>

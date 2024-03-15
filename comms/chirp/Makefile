PORTNAME=	chirp
DISTVERSION=	20240311
CATEGORIES=	comms hamradio
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DIST_SUBDIR=	chirp

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Free, open-source tool for programming your amateur radio
WWW=		https://chirpmyradio.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}versioningit>0:devel/py-versioningit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yattag>0:devel/py-yattag@${PY_FLAVOR}

USES=		desktop-file-utils gnome python shebangfix
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	kk7ds
GH_TAGNAME=	091f707b

USE_PYTHON=	autoplist pep517 pytest

USE_WX=		3.2
WX_COMPS=	python:run

PORTSCOUT=	ignore:1
NO_ARCH=	yes

PLIST_SUB+=	DISTVERSION="${DISTVERSION}"

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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>

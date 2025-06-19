PORTNAME=	chirp
DISTVERSION=	20240910
PORTREVISION=	3
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yattag>0:devel/py-yattag@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}suds>0:net/py-suds@${PY_FLAVOR}

USES=		desktop-file-utils gnome python:3.10+ shebangfix
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	kk7ds
GH_TAGNAME=	1ee5acb

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

.include <bsd.port.mk>

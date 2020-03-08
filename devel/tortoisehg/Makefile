# $FreeBSD$

PORTNAME=	tortoisehg
DISTVERSION=	5.1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/tortoisehg/thg/get/
DISTNAME=	${DISTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	GUI for Mercurial VCS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	hg:devel/mercurial
RUN_DEPENDS=	hg:devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}iniparse>=0.4:devel/py-iniparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}

USES=		pyqt:5 python:2.7
USE_PYQT=	core gui network qscintilla2 xml
USE_PYTHON=	distutils

OPTIONS_DEFINE=	NAUTILUS NLS
NAUTILUS_DESC=	Install TortoiseHG Nautilus extension
OPTIONS_SUB=	yes

NLS_USES=	gettext

NO_ARCH=	yes
SUB_FILES=	pkg-message
DIST_SUBDIR=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-thg-${TAGNAME}
TAGNAME=	89b2d1787506

# Do not conflict with devel/mercurial, which also installs hgext3rd/__init__.py
EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-thg-${TAGNAME}/hgext3rd/__init__.py

post-patch:
	@${REINPLACE_CMD} -e '/_path/ s|/usr|${PREFIX}|' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/contrib/tortoisehg.desktop
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/thg

post-patch-NLS-on:
	@${REINPLACE_CMD} -e 's/^%%NLS%%//' ${WRKSRC}/${PYSETUP}

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's/^%%NLS%%/# /' ${WRKSRC}/${PYSETUP}

post-patch-NAUTILUS-on:
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%//' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/${PYSETUP}

post-patch-NAUTILUS-off:
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%/# /' ${WRKSRC}/${PYSETUP}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tortoisehg
	${INSTALL_DATA} ${WRKSRC}/contrib/mergetools.rc ${STAGEDIR}${PREFIX}/share/tortoisehg/
	${INSTALL_DATA} ${WRKSRC}/contrib/tortoisehg.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>

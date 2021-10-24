PORTNAME=	tortoisehg
DISTVERSION=	6.0
CATEGORIES=	devel
MASTER_SITES=	https://www.mercurial-scm.org/release/tortoisehg/targz/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	GUI for Mercurial VCS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PY_MERCURIAL}
RUN_DEPENDS=	${PY_MERCURIAL} \
		${PYTHON_PKGNAMEPREFIX}iniparse>=0.4:devel/py-iniparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}

USES=		pyqt:5 python:3.5+
USE_PYQT=	qscintilla2 pyqt5
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	NAUTILUS NLS
NAUTILUS_DESC=	Install TortoiseHG Nautilus extension
OPTIONS_SUB=	yes

NLS_USES=	gettext

NO_ARCH=	yes
SUB_FILES=	pkg-message

# Do not conflict with devel/mercurial, which also installs hgext3rd/__init__.py
EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-${DISTVERSION}/hgext3rd/__init__.py

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif

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
	${INSTALL_DATA} ${WRKSRC}/contrib/thg.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/contrib/mergetools.rc ${STAGEDIR}${PREFIX}/share/tortoisehg/

.include <bsd.port.post.mk>

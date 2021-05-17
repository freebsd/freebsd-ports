PORTNAME=	tortoisehg
DISTVERSION=	5.8.0
CATEGORIES=	devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	GUI for Mercurial VCS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PY_MERCURIAL}
RUN_DEPENDS=	${PY_MERCURIAL} \
		${PYTHON_PKGNAMEPREFIX}iniparse>=0.4:devel/py-iniparse@${PY_FLAVOR} \
		${PY_PYGMENTS}

USES=		pyqt:5 python:3.5+
USE_PYQT=	core gui network qscintilla2 xml
USE_PYTHON=	distutils autoplist

USE_GITLAB=	yes
GL_SITE=	https://foss.heptapod.net
GL_ACCOUNT=	mercurial/tortoisehg
GL_PROJECT=	thg
GL_COMMIT=	65f0eafe3f398fabe0afbc475e18cd63af81df89
GL_HEPTAPOD_COMMIT=	9f108b8c92463866721dedda1f3f872e0e2b4344

OPTIONS_DEFINE=	NAUTILUS NLS
NAUTILUS_DESC=	Install TortoiseHG Nautilus extension
OPTIONS_SUB=	yes

NLS_USES=	gettext

WRKSRC=		${WRKDIR}/${GL_PROJECT}-${GL_COMMIT}-${GL_HEPTAPOD_COMMIT}
NO_ARCH=	yes
SUB_FILES=	pkg-message

# Do not conflict with devel/mercurial, which also installs hgext3rd/__init__.py
EXTRACT_AFTER_ARGS=	--exclude ${GL_PROJECT}-${GL_COMMIT}-${GL_HEPTAPOD_COMMIT}/hgext3rd/__init__.py

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
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

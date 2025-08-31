PORTNAME=	Uranium
DISTVERSION=	5.7.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Python framework for 3D printing applications
WWW=		https://github.com/Ultimaker/Uranium/blob/master/docs/overview.md

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyclipper>0:math/py-pyclipper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		cmake gettext python pyqt:6
USE_PYQT=	pyqt6
USE_PYTHON=	cryptography
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
STRIP=
NO_ARCH=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@for f in UraniumPluginInstall.cmake UraniumTests.cmake UraniumTranslationTools.cmake mod_bundled_packages_json.py; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}/cmake; \
		done
	@for f in CMakeLists.txt CPackConfig.cmake Doxyfile; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}; \
		done

#post-install:
#	${MKDIR} ${STAGEDIR}${PREFIX}/share/uranium/scripts
#	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/uranium/scripts

.include <bsd.port.mk>

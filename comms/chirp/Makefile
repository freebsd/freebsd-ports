PORTNAME=	chirp
PORTVERSION=	20230731
PORTREVISION=	1
CATEGORIES=	comms hamradio
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DIST_SUBDIR=	chirp

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Free, open-source tool for programming your amateur radio
WWW=		https://chirp.danplanet.com/projects/chirp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioningit>0:devel/py-versioningit@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yattag>0:devel/py-yattag@${PY_FLAVOR}

USES=		desktop-file-utils gnome python shebangfix
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	kk7ds
GH_TAGNAME=	c49fb6d8a46270a47718b0b4857695d5d0d83780

USE_GNOME=	gtk-update-icon-cache

USE_PYTHON=	autoplist pep517 pytest

USE_WX=	3.2
WX_COMPS=	python:run

PLIST_FILES=	share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTSCOUT=	ignore:1
NO_ARCH=	yes

post-patch:
	@${ECHO} "Version: ${PORTVERSION}" > ${WRKSRC}/PKG-INFO

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/share && \
		${INSTALL_DATA} ${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps && \
		${INSTALL_DATA} ${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>

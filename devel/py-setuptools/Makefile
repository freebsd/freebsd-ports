# $FreeBSD$

PORTNAME=	setuptools
PORTVERSION=	5.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python packages installer

LICENSE=	PSFL

# This creates a dependency loop
#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}distribute-[0-9]*

PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION} \
		EASYINSTALL_PTH=${PYTHON_SITELIBDIR}/easy-install.pth

USES=		python
USE_PYTHON=	autoplist distutils
PYDISTUTILS_SETUP=	${PYSETUP}

SUB_LIST=	IF_DEFAULT=${IF_DEFAULT}

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} != ${PYTHON_DEFAULT_VERSION}
SUB_FILES+=	pkg-message
.endif

post-patch:
.if ${PYTHON_VERSION} != ${PYTHON_DEFAULT_VERSION}
	@${REINPLACE_CMD} 's,.*yield "easy_install =.*,,' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} 's,#!python,#!${PYTHON_CMD},' \
		${WRKSRC}/setuptools/command/easy_install.py
	@${REINPLACE_CMD} 's,#!/usr/bin/python,#!${PYTHON_CMD},' \
		${WRKSRC}/setuptools/tests/test_resources.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/easy-install.pth.dist ${STAGEDIR}${PYTHON_SITELIBDIR}/

#regression-test: build
#	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.post.mk>

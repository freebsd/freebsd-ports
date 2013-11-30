# $FreeBSD$

PORTNAME=	setuptools
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python packages installer

LICENSE=	PSFL

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}distribute-[0-9]*

PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION} \
		EASYINSTALL_PTH=${PYTHON_SITELIBDIR}/easy-install.pth

PYDISTUTILS_NOEGGINFO=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYTHON_PY3K_PLIST_HACK=	yes

SUB_LIST=	IF_DEFAULT=${IF_DEFAULT}

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == ${PYTHON_DEFAULT_VERSION} && !exists(${LOCALBASE}/bin/easy_install)
PLIST_SUB+=	IF_DEFAULT=""
.else
PLIST_SUB+=	IF_DEFAULT="@comment "
SUB_FILES+=	pkg-message
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/easy-install.pth.dist ${STAGEDIR}${PYTHON_SITELIBDIR}/

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.post.mk>

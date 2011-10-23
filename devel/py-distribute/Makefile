# New ports collection makefile for:	py-distribute
# Date created:		2010-05-06
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distribute
PORTVERSION=	0.6.24
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A Python packages installer, and Setuptools replacement

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}setuptools-[0-9]*

PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION} SETUPTOOLS_VER=0.6c11

PYDISTUTILS_NOEGGINFO=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

SUB_FILES=	pkg-install
SUB_LIST=	EASYINSTALL_PTH=${EASYINSTALL_PTH} \
		IF_DEFAULT=${IF_DEFAULT}

EASYINSTALL_PTH=	${PYTHON_SITELIBDIR}/easy-install.pth
SITE_PY=	${PYTHON_SITELIBDIR}/site.py
PYFILES=	site.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 320
PYCACHE=	__pycache__/%%PYMOD%%.cpython-${PYTHON_VER:S,.,,}
PLIST_DIRS=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/__pycache__
.else
PYCACHE=	%%PYMOD%%
.endif

.for m in ${PYFILES}
.for ext in pyc pyo
PLIST_FILES+=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/${PYCACHE:S,%%PYMOD%%,${m:R},}.${ext}
.endfor
.endfor

.if ${PYTHON_VERSION} == ${PYTHON_DEFAULT_VERSION} && !exists(${LOCALBASE}/bin/easy_install)
PLIST_SUB+=	IF_DEFAULT=""
.else
PLIST_SUB+=	IF_DEFAULT="@comment "
SUB_FILES+=	pkg-message
SUB_LIST+=	PYVER=${PYTHON_VER}

# remove the console script easy_install
post-patch:
	@${REINPLACE_CMD} -e '/easy_install = / s|".*"||' ${WRKSRC}/setup.py
.endif

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/site.py ${SITE_PY}
	${PYTHON_CMD} -m py_compile ${SITE_PY}
	${PYTHON_CMD} -OO -m py_compile ${SITE_PY}
	${CP} ${EASYINSTALL_PTH} ${EASYINSTALL_PTH}.dist
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	if [ -f ${PKGMESSAGE} ]; then ${CAT} ${PKGMESSAGE}; fi

.include <bsd.port.post.mk>

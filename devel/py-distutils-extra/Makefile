# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	distutils-extra
PORTVERSION=	2.38
CATEGORIES=	devel python
MASTER_SITES=	https://launchpadlibrarian.net/145592954/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add support for i18n, documentation, and icons to distutils

LICENSE=	GPLv2

NO_STAGE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	python_distutils_extra
PYDISTUTILS_NOEGGINFO=	yes
PYTHON_PY3K_PLIST_HACK=	yes

PLIST_SUB=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

.include <bsd.port.pre.mk>

#.if ${PYTHON_REL} >= 320
#PLIST_SUB+=	PYTHON32=""
#.else
#PLIST_SUB+=	PYTHON32="@comment "
#.endif

post-install:
.if ${PYTHON_REL} >= 320
#.for py in __init__.py command/__init__.py command/build_extra.py
#	${PYTHON_CMD} -m compileall ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/DistUtilsExtra/${py}
#.endfor
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	py-ruledispatch
# Date created:		15 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	RuleDispatch
PORTVERSION=	0.5.a0.r2115
CATEGORIES=	devel python
MASTER_SITES=	http://harry.turbogears.org/eggs/ \
		http://dryice.name/computer/FreeBSD/distfiles/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-0.5a0.dev-r2115

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Rule-based Dispatching and Generic Functions

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/${PYPROTOCOLS_EGG}:${PORTSDIR}/devel/py-protocols-devel

NO_PACKAGE=	not yet

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.5a0

PLIST_FILES+=	lib/${PYTHON_VERSION}/site-packages/${PYRULEDISPATCH_EGG}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="RuleDispatch==${PYRULEDISPATCH_VER}"

PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's
OSINFOS=	${OPSYS:L}-${OSRELEASE}-${ARCH}
PYRULEDISPATCH_EGG=	${PORTNAME}-${PYRULEDISPATCH_VER}-py${PYTHON_VERSION:S/^python//}-${OSINFOS}.egg
PYRULEDISPATCH_VER?=	0.5a0

SETUP_CFG=	setup.cfg

post-extract:
	${CP} ${FILESDIR}/${SETUP_CFG} ${WRKSRC}

.include <bsd.port.pre.mk>

OSRELEASE!=	${DESTDIR}/usr/bin/uname -r
PYPROTOCOLS_EGG!=	${MAKE} -f ${PORTSDIR}/devel/py-protocols-devel/Makefile -V PYPROTOCOLS_EGG

.include <bsd.port.post.mk>

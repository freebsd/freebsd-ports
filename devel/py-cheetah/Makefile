# New ports collection makefile for:	py-cheetah
# Date created:		26 November 2003
# Whom:	      		Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cheetah
PORTVERSION=	2.4.2.1
PORTREVISION=	0
CATEGORIES=	devel textproc www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cheetah-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	HTML template engine for Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=2.0.3:${PORTSDIR}/textproc/py-markdown

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PYDISTUTILS_PKGNAME=	Cheetah
PYEASYINSTALL_ARCHDEP=	yes
PYEASYINSTALL_INSTALLARGS=	-N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
PYEASYINSTALL_UNINSTALLARGS=	-q -m -N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}

.include <bsd.port.mk>

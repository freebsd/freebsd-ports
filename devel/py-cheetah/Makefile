# New ports collection makefile for:	py-cheetah
# Date created:		26 November 2003
# Whom:	      		Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cheetah
PORTVERSION=	2.2.1
PORTREVISION=	0
CATEGORIES=	devel textproc www python
MASTER_SITES=	SF/${PORTNAME}template/Cheetah/v${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cheetah-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	HTML template engine for Python

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	cheetah-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	Cheetah
PYEASYINSTALL_ARCHDEP=	yes
PYEASYINSTALL_INSTALLARGS=	-N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
PYEASYINSTALL_UNINSTALLARGS=	-q -m -N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
MAKE_ENV=	CHEETAH_USE_SETUPTOOLS=yes

.include <bsd.port.mk>

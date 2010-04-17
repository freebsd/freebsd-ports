# New ports collection makefile for: py-greenlet
# Date created:		6 Feb 2010
# Whom:			Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$
#

PORTNAME=	greenlet
PORTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/g/greenlet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	greenlet-${PORTVERSION}

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Light-weight microthreads for Python

ONLY_FOR_ARCHS=		amd64 i386
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	greenlet
PYEASYINSTALL_ARCHDEP=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>

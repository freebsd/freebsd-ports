# New ports collection makefile for:	py-versiontools
# Date created:				13 April 2012
# Whom:					Ruslan Mahmatkhanov <rm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	versiontools
PORTVERSION=	1.9.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Smart replacement for plain tuple used in __version__

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>

# Created by: Roland van Laar <roland@micite.net>
# $FreeBSD$

PORTNAME=	pycalendar
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	roland@micite.net
COMMENT=	An iCalendar and vCard module for python

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|distutils.core|setuptools|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>

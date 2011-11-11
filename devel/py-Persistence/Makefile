# New ports collection makefile for:	py-Persistence
# Date created:				Nov 11, 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	Persistence
PORTVERSION=	2.13.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Persistent ExtensionClass

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:${PORTSDIR}/devel/py-ExtensionClass \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3

PYEASYINSTALL_ARCHDEP=	yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=		yes

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	Products.ZCTextIndex
PORTVERSION=	2.13.4
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Full text indexing for ZCatalog/Zope2

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:${PORTSDIR}/security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:${PORTSDIR}/devel/py-Persistence \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:${PORTSDIR}/devel/py-zExceptions \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface

PYEASYINSTALL_ARCHDEP=	yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=		yes

NO_STAGE=	yes
.include <bsd.port.mk>

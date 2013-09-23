# $FreeBSD$

PORTNAME=	Persistence
PORTVERSION=	2.13.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Persistent ExtensionClass

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:${PORTSDIR}/devel/py-ExtensionClass \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3

PYEASYINSTALL_ARCHDEP=	yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=		yes

NO_STAGE=	yes

.include <bsd.port.mk>

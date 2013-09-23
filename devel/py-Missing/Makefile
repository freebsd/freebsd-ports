# $FreeBSD$

PORTNAME=	Missing
PORTVERSION=	2.13.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Special Missing objects used in Zope2

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:${PORTSDIR}/devel/py-ExtensionClass

PYEASYINSTALL_ARCHDEP=	yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=		yes

NO_STAGE=	yes

.include <bsd.port.mk>

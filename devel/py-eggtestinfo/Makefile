# $FreeBSD$

PORTNAME=	eggtestinfo
PORTVERSION=	0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Setuptools plugin that adds test information to .egg-info

LICENSE=	ZPL21

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>

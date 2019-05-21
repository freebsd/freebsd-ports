# $FreeBSD$

PORTNAME=	knock
DISTVERSION=	4.1.0-27
DISTVERSIONSUFFIX=	-ge2c98df
CATEGORIES=	dns
PKGNAMESUFFIX=	py

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool designed to enumerate subdomains on a target domain

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	guelfoweb
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

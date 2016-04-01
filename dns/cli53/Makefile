# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cli53
PORTVERSION=	0.4.4
CATEGORIES=	dns

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Command line management of Route53 domains

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	barnybug

.include <bsd.port.mk>

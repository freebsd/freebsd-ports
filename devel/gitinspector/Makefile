PORTNAME=	gitinspector
PORTVERSION=	0.4.4
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	devel python
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Statistical analysis tool for git repositories
WWW=		https://github.com/ejwa/gitinspector

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	git:devel/git

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

GH_ACCOUNT=	ejwa
USE_GITHUB=	yes

.include <bsd.port.mk>

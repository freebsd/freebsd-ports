PORTNAME=	click-default-group
PORTVERSION=	1.2.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	click_default_group-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extend click.Group to invoke a command without explicit subcommand name
WWW=		https://github.com/click-contrib/click-default-group

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

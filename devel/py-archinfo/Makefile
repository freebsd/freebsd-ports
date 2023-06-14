PORTNAME=	archinfo
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classes with architecture-specific information useful to other projects
WWW=		https://github.com/angr/archinfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyvex>0:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicorn>0:emulators/py-unicorn@${PY_FLAVOR}

USES=		angr:nose python
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

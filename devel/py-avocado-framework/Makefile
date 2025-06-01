PORTNAME=	avocado-framework
DISTVERSION=	110.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Set of tools and libraries to help with automated testing
WWW=		https://avocado-framework.github.io/

LICENSE=	GPLv2+

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	avocado
USE_PYTHON=	autoplist distutils

PYDISTUTILS_INSTALLARGS+=	--etcprefix="${PREFIX}"

NO_ARCH=	yes

.include <bsd.port.mk>

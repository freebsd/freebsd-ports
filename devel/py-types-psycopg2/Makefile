PORTNAME=	types-psycopg2
PORTVERSION=	2.9.21.20250318
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Typing stubs for psycopg2
WWW=		https://pypi.org/project/types-psycopg2/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>

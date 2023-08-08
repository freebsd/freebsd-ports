PORTNAME=	fields
PORTVERSION=	5.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Totally different take on container boilerplate
WWW=		https://github.com/ionelmc/python-fields

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/ionelmc/python-fields/issues/9

NO_ARCH=	yes

.include <bsd.port.mk>

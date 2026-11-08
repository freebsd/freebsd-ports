PORTNAME=	django-pgware
DISTVERSION=	1.0.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL utilities for Django
WWW=		https://github.com/Xof/django-pgware

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.28.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "PostgreSQL"|license = { text = "PostgreSQL" }|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>

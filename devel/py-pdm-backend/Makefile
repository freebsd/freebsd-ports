PORTNAME=	pdm-backend
PORTVERSION=	2.4.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pdm_backend-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Build backend used by PDM that supports latest packaging standards
WWW=		https://backend.pdm-project.org/ \
		https://github.com/pdm-project/pdm-backend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

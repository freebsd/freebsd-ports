PORTNAME=	all-repos
PORTVERSION=	1.26.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	all_repos-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Clone all your repositories and apply sweeping changes
WWW=		https://github.com/asottile/all-repos

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		jq:textproc/jq \
		${PYTHON_PKGNAMEPREFIX}identify>=0:devel/py-identify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}contextlib-chdir>=0:devel/py-contextlib-chdir@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>

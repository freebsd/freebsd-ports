# $FreeBSD$

PORTNAME=	path.py
PORTVERSION=	8.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Module wrapper for os.path

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	jaraco

post-patch:
	@${REINPLACE_CMD} -e '/setuptools_scm/d' \
		-e 's/use_scm_version=True,/version=${PORTVERSION},/' \
		${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>

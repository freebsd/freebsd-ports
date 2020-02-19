# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	freebsd
PORTVERSION=	0.9.4
DISTVERSIONPREFIX=v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FreeBSD-specific system libraries

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	sobomax
GH_PROJECT=	py-${PORTNAME}

PYDISTUTILS_BUILD_TARGET=build_ext -i

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/freebsd.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover tests -v

.include <bsd.port.mk>

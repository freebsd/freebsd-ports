# Created by: db
# $FreeBSD$

PORTNAME=	ephem
PORTVERSION=	3.7.7.0
CATEGORIES=	astro math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Compute positions of the planets and stars

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ephem/_libastro.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>

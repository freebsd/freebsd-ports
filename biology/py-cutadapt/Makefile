# $FreeBSD$

PORTNAME=	cutadapt
PORTVERSION=	1.14
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Finds and removes adapter sequences, primers, poly-A tails, etc

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xopen>0:archivers/py-xopen@${FLAVOR}

USES=		python
USE_PYTHON=	distutils py3kplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cutadapt/*.so

.include <bsd.port.mk>

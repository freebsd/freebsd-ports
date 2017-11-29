# $FreeBSD$

PORTNAME=	cutadapt
PORTVERSION=	1.14
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/c/cutadapt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Finds and removes adapter sequences, primers, poly-A tails, etc

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xopen>0:archivers/py-xopen

USES=		python
USE_PYTHON=	distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cutadapt/*.so

.include <bsd.port.mk>

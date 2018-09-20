# $FreeBSD$

PORTNAME=	cutadapt
PORTVERSION=	1.18
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trim adapters from high-throughput sequencing reads

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xopen>=0.3.2:archivers/py-xopen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bz2file>=0.98:archivers/py-bz2file@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cutadapt/*.so

.include <bsd.port.mk>

PORTNAME=	dnaio
DISTVERSION=	0.5.1	# py-cutadapt 3.3 requires 0.5.x
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Read and write FASTQ and FASTA

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	argparse
PORTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An optparse-inspired command-line parsing library

USE_ZIP=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/argparse.py \
		%%PYTHON_SITELIBDIR%%/argparse.pyc \
		%%PYTHON_SITELIBDIR%%/argparse.pyo

NO_STAGE=	yes
.include <bsd.port.mk>

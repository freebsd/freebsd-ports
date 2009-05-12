# New ports collection makefile for:	py-argparse
# Date created:		Jan. 05, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	argparse
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An optparse-inspired command-line parsing library

USE_ZIP=	yes

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/argparse.py \
		%%PYTHON_SITELIBDIR%%/argparse.pyc \
		%%PYTHON_SITELIBDIR%%/argparse.pyo

.include <bsd.port.mk>

# New ports collection makefile for:	py-gdata
# Date created:		Mar. 28, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	gdata
PORTVERSION=	1.0.3
CATEGORIES=	devel python
MASTER_SITES=	http://gdata-python-client.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gdata.py-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	GData Python Client Library

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

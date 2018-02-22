# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	xoltar-toolkit
PORTVERSION=	2001.06.01
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/xoltar%20toolkit/June%202001
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-01jun01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Functional programming, lazy expressions, and thread pools for Python

LICENSE=	LGPL21+

USES=		python:2.7
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py* ${STAGEDIR}${PYTHON_SITELIBDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pyrex
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	devel lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyrex-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Programming Language for writing Python extension modules

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-11-15

USES=		python:2.7
USE_PYTHON=	autoplist distutils

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/Doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/Demos && ${MAKE} clean && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

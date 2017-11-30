# Created by: Jacob Myers (jacob@whotookspaz.org)
# $FreeBSD$

PORTNAME=	akismet
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.voidspace.org.uk/downloads/ \
		http://whotookspaz.org/misc/freebsd/py-akismet/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jacob@whotookspaz.org
COMMENT=	Python interface to the Akismet API

LICENSE=	BSD3CLAUSE

USES=		python:2.7 zip
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	akismet

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	enum34
PORTVERSION=	1.1.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python 3.4 Enum backported to 3.3, 3.2, 3.1, 2.7

LICENSE=	BSD3CLAUSE

# Should be removed along with python2.7 and relevant vairables PY_ENUM34
# EXPIRATION_DATE or python27 whichever happens later should be followed
DEPRECATED=	Will be removed along with python27
EXPIRATION_DATE=2020-12-31

USES=		python:2.7
USE_PYTHON=	distutils autoplist
OPTIONS_DEFINE=	DOCS

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
NO_ARCH=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/enum/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

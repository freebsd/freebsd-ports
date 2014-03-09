# $FreeBSD$

PORTNAME=	Pyrseas
PORTVERSION=	0.7.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arcade@b1t.name
COMMENT=	Framework and utilities to upgrade and maintain a relational database

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jmafc
GH_COMMIT=	9b0e3d2
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTNAME}-${GH_COMMIT}

.include <bsd.port.mk>

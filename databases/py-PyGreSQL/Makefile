# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	PyGreSQL
PORTVERSION=	5.0.3
PORTEPOCH=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python interface to PostgreSQL, both classic and DP-API 2.0

LICENSE=	PSFL

USES=		pgsql python
USE_PYTHON=	autoplist distutils

PORTDOCS=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pg.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

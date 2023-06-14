PORTNAME=	PyGreSQL
PORTVERSION=	5.2
PORTEPOCH=	1
CATEGORIES=	databases python
MASTER_SITES=	http://www.pygresql.org/files/ \
		PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python interface to PostgreSQL, both classic and DP-API 2.0
WWW=		http://www.pygresql.org/

LICENSE=	PSFL

USES=		pgsql python
USE_PYTHON=	autoplist distutils

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pg*.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

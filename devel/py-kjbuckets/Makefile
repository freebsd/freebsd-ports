# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=		kjbuckets
PORTVERSION=		1.0.0
PORTEPOCH=		1
CATEGORIES=		devel python
MASTER_SITES=		SF/gadfly/gadfly/${PORTVERSION}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		gadfly-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Graph and set datatypes for Python (C extension)

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
WRKSRC=			${WRKDIR}/${DISTNAME}/kjbuckets

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../COPYRIGHT.txt ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/kjbuckets.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/demo/kjbuckets/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

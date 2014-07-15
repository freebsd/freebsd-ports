# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pg_pqueue
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://python.projects.postgresql.org/files/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	PostgreSQL PQ Protocol Modules

LICENSE=	BSD

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>
post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/changes.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>

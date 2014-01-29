# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pg_pqueue
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://python.projects.postgresql.org/files/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	PostgreSQL PQ Protocol Modules

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/changes.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

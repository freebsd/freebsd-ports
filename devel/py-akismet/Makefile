# Created by: Jacob Myers (jacob@whotookspaz.org)
# $FreeBSD$

PORTNAME=	akismet
PORTVERSION=	0.2.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.voidspace.org.uk/downloads/ \
		http://whotookspaz.org/misc/freebsd/py-akismet/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jacob@whotookspaz.org
COMMENT=	A Python interface to the Akismet API

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	akismet

USE_ZIP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>

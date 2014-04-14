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

LICENSE=	BSD

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	akismet

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>

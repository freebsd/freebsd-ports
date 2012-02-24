# New ports collection makefile for:	py-pylib
# Date created:		2008-09-16
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pylib
PORTVERSION=	1.4.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/p/py
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	An agile development and test support library

LICENSE=	MIT

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	py
USE_ZIP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGELOG README.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
IGNORE=		has not yet been ported to sparc64
.endif

.include <bsd.port.post.mk>

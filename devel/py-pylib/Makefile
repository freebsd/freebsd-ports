# New ports collection makefile for:	py-pylib
# Date created:		2008-09-16
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pylib
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/p/py
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTVERSION}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	An agile development and test support library

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	py

PLIST_SUB+=	PY_VER=${PYTHON_VERSION:S,python,,}

WRKSRC=		${WRKDIR}/${DISTNAME}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGELOG LICENSE README.txt

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

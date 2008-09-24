# New ports collection makefile for:	py-pylib
# Date created:		2008-09-16
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pylib
PORTVERSION=	0.9.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/p/py
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTVERSION}

MAINTAINER=	yzlin@cs.nctu.edu.tw
COMMENT=	An agile development and test support library

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	py
PYEASYINSTALL_ARCHDEP=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGELOG LICENSE README.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>

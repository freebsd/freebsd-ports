# New ports collection makefile for:	py-graph
# Date created:		2008-08-29
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	graph
PORTVERSION=	1.4.2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-graph-${PORTVERSION}

MAINTAINER=	yzlin@cs.nctu.edu.tw
COMMENT=	A library for working with graphs in Python

BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

PROJECTHOST=	python-graph
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python-graph

WRKSRC=		${WRKDIR}/${PYDISTUTILS_PKGNAME}

USE_BZIP2=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

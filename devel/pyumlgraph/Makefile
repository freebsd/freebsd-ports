# ex:ts=8
# Ports collection makefile for:	PyUMLGraph
# Date created:			Mar 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyumlgraph
PORTVERSION=	0.1.10
CATEGORIES=	devel
MASTER_SITES=	http://adamfeuer.com/~adamf/software/PyUMLGraph/
DISTNAME=	PyUMLGraph-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Declarative Drawing of UML diagrams for Python

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_FILES=	bin/pyumlgraph
PORTDOCS=	*

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/PyUMLGraph -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/PyUMLGraph -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

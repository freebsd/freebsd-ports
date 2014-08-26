# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codeville
PORTVERSION=	0.1.16
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://bsdforge.com/projects/source/devel/codeville/
DISTNAME=	Codeville-${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Anarchic control version system without unnecessary re-merges

LICENSE=	BSD3CLAUSE

USES=		python tar:xz
USE_PYTHON=	distutils autoplist

PORTDOCS=	LICENSE.txt
PORTEXAMPLES=	cdvserver.conf.sample

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
# examples
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
# documentation
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

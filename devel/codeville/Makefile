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

USES=		tar:xz
USE_PYTHON=	yes

USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	Codeville

PORTDOCS=	LICENSE.txt
EXAMPLE_FILES=	cdvserver.conf.sample

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
# examples
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/${EXAMPLE_FILES} ${STAGEDIR}${EXAMPLESDIR}
# documentation
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

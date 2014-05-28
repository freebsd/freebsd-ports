# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	gvgen
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Easy python interface to generate dot files

LICENSE=	GPLv2

USE_GITHUB=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes
GH_ACCOUNT=	stricaud
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	777ab06

OPTIONS=	DOCS

PORTDOCS=	crypto-folks.png gvgen-legend.png gvgen-propertyforeachlinks.2.png \
	      	gvgen-smartmode-2.png gvgen-cluster-node-link.png gvgen-legendin.png \
		gvgen-propertylink.png gvgen-styles.png gvgen-defaultstyle.png \
   		gvgen-links.png gvgen-smartmode-1.png

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

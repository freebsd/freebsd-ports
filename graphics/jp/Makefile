# $FreeBSD$

PORTNAME=	jp
DISTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Terminal charts, plots, histograms and maps from JSON and CSV

LICENSE=	MIT APACHE20
LICENSE_COMB=	multi

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	sgreben
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "README.md docs" ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

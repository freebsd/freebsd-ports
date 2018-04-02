# $FreeBSD$

PORTNAME=	uperf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6.20180221
CATEGORIES=	benchmarks

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Network performance tool to model and replay of networking patterns

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ssl

USE_GITHUB=	yes
GH_TAGNAME=	25ad9ff

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${DATADIR}/workloads

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS \
		README.md

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/tests
	(cd ${WRKSRC}/tests && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/tests \
	"! -name Makefile.in ! -name Makefile.am ! -name Makefile")

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	(cd ${WRKSRC}/docs && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/docs "! -name CNAME")
	${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	(cd ${WRKSRC}/manual && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/manual "! -name Makefile")

.include <bsd.port.mk>

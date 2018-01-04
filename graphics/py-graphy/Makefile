# Created by: Sahil Tandon <sahil@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphy
PORTVERSION=	1.0
CATEGORIES=	graphics python
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/graphy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple chart library for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:run tar:bzip2
USE_PYTHON=	flavors

PORTDOCS=	README
PORTEXAMPLES=	*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|python2.4|${PYTHON_VERSION}|' \
		${WRKSRC}/examples/*.py \
		${WRKSRC}/${PORTNAME}/*.py
	@${FIND} ${WRKSRC} -name '.svn' -or -name '*.bak' | \
		${XARGS} ${RM} -r

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	@(cd ${WRKSRC}/${PORTNAME}/ && \
	     ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME})
post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

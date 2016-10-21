# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	funcparserlib
PORTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Recursive descent parsing library based on functional combinators

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	README doc
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${WRKSRC}/doc/Makefile
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;

.include <bsd.port.mk>

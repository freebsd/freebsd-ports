# Created by: ijliao
# $FreeBSD$

PORTNAME=	ply
PORTVERSION=	3.4
CATEGORIES=	devel python
MASTER_SITES=	http://www.dabeaz.com/ply/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python Lex-Yacc

LICENSE=	BSD3CLAUSE

USES=		python
PYTHON_FEATURES=autoplist distutils

PORTDOCS=	ply.html internal.html README

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
	@${REINPLACE_CMD} -e 's|from setuptools import setup|from distutils.core import setup|' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/internal.html ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

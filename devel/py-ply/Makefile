# Created by: ijliao
# $FreeBSD$

PORTNAME=	ply
PORTVERSION=	3.9
CATEGORIES=	devel python
MASTER_SITES=	http://www.dabeaz.com/ply/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Lex-Yacc

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	ply.html internal.html

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/internal.html ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

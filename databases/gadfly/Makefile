# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gadfly
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SQL database written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/kjbuckets.so:devel/py-kjbuckets@${FLAVOR}

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/build_html.py ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/kjParsing
	${INSTALL_DATA} ${WRKSRC}/doc/demo/kjParsing/*.py \
		${STAGEDIR}${EXAMPLESDIR}/kjParsing

.include <bsd.port.mk>

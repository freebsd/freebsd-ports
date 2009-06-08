# New ports collection makefile for:    gadfly
# Date created:         30 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gadfly
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SQL database written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/kjbuckets.so:${PORTSDIR}/devel/py-kjbuckets

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/build_html.py ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/kjParsing
	@${INSTALL_DATA} ${WRKSRC}/doc/demo/kjParsing/*.py \
		${EXAMPLESDIR}/kjParsing
.endif

.include <bsd.port.mk>

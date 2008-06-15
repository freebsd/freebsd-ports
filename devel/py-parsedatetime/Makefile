# New ports collection makefile for:	py-parsedatetime
# Date created:		Feb. 24, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	parsedatetime
PORTVERSION=	0.8.6
CATEGORIES=	devel python
MASTER_SITES=	http://code-bear.com/code/parsedatetime/ \
		CHEESESHOP \
		${MASTER_SITE_GOOGLE_CODE} \
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python module for parsing 'human readable' date/time expressions

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
EXAMPLES=	README.txt basic.py with_locale.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	tpg
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tpg
PORTVERSION=	2.1.3
CATEGORIES=	devel python
MASTER_SITES=	http://christophe.delord.free.fr/soft/tpg/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	sergei@kolobov.com

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
NO_BUILD=	yes

EXAMPLES=	calc.g calc.py calc2.py notation.py

post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/calc/${file} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tpg.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	dnspython
# Date created:				Sun Dec 26 09:58:59 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dnspython
PORTVERSION=	1.3.3
CATEGORIES=	dns python
MASTER_SITES=	http://www.dnspython.org/kits/stable/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A DNS toolkit for Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PORTDOCS=	\
		ChangeLog \
		README \
		TODO
EXAMPLE_FILES=	\
		mx.py \
		name.py \
		reverse.py \
		xfr.py

post-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
# examples
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

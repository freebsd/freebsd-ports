# New ports collection makefile for:	pydasm
# Date created:				23 March 2006
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	pydasm
PORTVERSION=	1.5
CATEGORIES=	devel python
MASTER_SITES=	http://www.klake.org/~jt/misc/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	libdasm-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	A python interface to libdasm

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/das.py ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>

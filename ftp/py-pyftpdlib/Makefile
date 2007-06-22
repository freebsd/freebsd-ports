# New ports collection makefile for:	py-pyftpdlib
# Date created:		Mar. 06, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	pyftpdlib
PORTVERSION=	0.1.1
CATEGORIES=	ftp python
MASTER_SITES=	http://pyftpdlib.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python FTP server library

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${TARGETDIR}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/demo/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	py-bulksms
# Date created:		06 Dec 2003
# Whom:			Andy Gilligan <andy@evo6.org>
#
# $FreeBSD$
#

PORTNAME=	bulksms
PORTVERSION=	0.1
CATEGORIES=	comms python
MASTER_SITES=	http://botanicus.net/dw.old/dl/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andy@evo6.org
COMMENT=	Python client for the BulkSMS.co.uk HTTP API

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

WRKSRC=		${WRKDIR}/bulksms

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>

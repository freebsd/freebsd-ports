# New ports collection makefile for:	py-configobj
# Date created:		2006-10-20
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	configobj
PORTVERSION=	4.3.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHONPKGNAMEPREFIX}

MAINTAINER=	whitekid@gmail.com
COMMENT=	Simple but powerful config file reader and writer

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

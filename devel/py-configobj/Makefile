# New ports collection makefile for:	py-configobj
# Date created:		2006-10-20
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	configobj
PORTVERSION=	4.4.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple but powerful config file reader and writer

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

# www/py-turbogears requires (and installs) a Python egg for ConfigObj
CONFLICTS=	py*-TurboGears-[0-9]*

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

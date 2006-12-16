# New ports collection makefile for:	py-zopeInterface
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	zopeInterface
PORTVERSION=	3.1.0c1
CATEGORIES=	devel zope python
MASTER_SITES=	http://www.zope.org/Products/ZopeInterface/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}/ZopeInterface-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	neal@nelson.name
COMMENT=	Zope.interface package from Zope 3

WRKSRC=		${WRKDIR}/ZopeInterface-${PORTVERSION}
USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	S=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	PyChart
# Date created:			Aug 4, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	chart
PORTVERSION=	1.28.1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.hpl.hp.com/personal/Yasushi_Saito/pychart/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyChart-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Create high quality Encapsulated Postscript, PDF, or PNG charts

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>

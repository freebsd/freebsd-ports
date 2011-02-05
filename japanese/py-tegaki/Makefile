# New ports collection makefile for:	py-tegaki

# Date created:				15 Aug 2010
# Whom:					Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	tegaki
PORTVERSION=	0.3.1
CATEGORIES=	japanese python
MASTER_SITES=	http://www.tegaki.org/releases/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Open-Source Chinese and Japanese Handwriting Recognition

LIB_DEPENDS=	zinnia.0:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/zinnia.py:${PORTSDIR}/japanese/py-zinnia

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}_python

.include <bsd.port.mk>

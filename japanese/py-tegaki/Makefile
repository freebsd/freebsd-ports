# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	tegaki
PORTVERSION=	0.3.1
CATEGORIES=	japanese python
MASTER_SITES=	http://www.tegaki.org/releases/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Open-source Chinese and Japanese handwriting recognition

LICENSE=	GPLv2

LIB_DEPENDS=	libzinnia.so:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/zinnia.py:${PORTSDIR}/japanese/py-zinnia

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}_python

.include <bsd.port.mk>

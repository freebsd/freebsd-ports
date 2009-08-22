# Ports collection makefile for:	py-rrdtool_lgpl
# Date created:			8 January 2003
# Whom:	      			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	rrdtool_lgpl
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	SF/py-rrdtool/py-rrdtool/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-rrdtool-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to RRDTool, the graphing and logging utility

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	py-rrdtool

LIBDIR?=	${LOCALBASE}/lib # directory where librrd.so lives

.include <bsd.port.mk>

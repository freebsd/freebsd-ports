# New ports collection makefile for:	mypaint
# Date created:		12 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mypaint
PORTVERSION=	0.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast painting/scribbling program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		swig:${PORTSDIR}/devel/swig13

USE_BZIP2=	yes
USE_GNOME=	glib20 pygtk2
USE_PYTHON=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix="${PREFIX}"

.include <bsd.port.mk>

# New ports collection makefile for:	py-gimp
# Date created:		2006-12-31
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/py-gimp/Makefile,v 1.6 2009/08/25 00:06:39 marcus Exp $

PORTREVISION=	0
PORTEPOCH=	0
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GIMP python plugin

GIMP_SLAVE=	pygimp

USE_PYTHON=	yes
USE_GNOME=	pygtk2

CONFIGURE_ARGS=	--enable-python
PLIST=	${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/plug-ins/pygimp
INSTALL_WRKSRC=	${WRKSRC}/plug-ins/pygimp

MASTERDIR=	${.CURDIR}/../../graphics/gimp-app

.include "${MASTERDIR}/Makefile"

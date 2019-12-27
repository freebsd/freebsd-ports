# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	gimp
DISTVERSION?=	2.10.14
PORTEPOCH?=	2
CATEGORIES=	graphics gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for The Gimp

RUN_DEPENDS=	gimp-2.10:graphics/gimp-app

USES+=	metaport

OPTIONS_DEFINE=	PYTHON PRINT HELP
OPTIONS_DEFAULT=PYTHON PRINT HELP
PYTHON_DESC=	Python-fu support
PRINT_DESC=	Gutenprint (gimp-print) plugin
HELP_DESC=	Gimp-Help (50+MB distfile)

HELP_RUN_DEPENDS+=	en-gimp-help-html>=0:misc/gimp-help-en
PYTHON_RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/environ/pygimp.env:graphics/py-gimp
PRINT_RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/plug-ins/gutenprint:print/gimp-gutenprint
PRINT_RUN_DEPENDS+=	gutenprint>0:print/gutenprint

.include <bsd.port.mk>

# Created by: erich@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/graphics/gimp/Makefile,v 1.22 2012/11/26 13:31:16 kwm Exp $

PORTNAME=	gimp
DISTVERSION?=	2.8.8
PORTREVISION?=	0
PORTEPOCH?=	2
CATEGORIES=	graphics gnome
MASTER_SITES?=	# empty
DISTFILES?=	# empty
EXTRACT_ONLY?=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for The Gimp

RUN_DEPENDS=	gimp-2.8:${PORTSDIR}/graphics/gimp-app

OPTIONS_DEFINE=	PYTHON PRINT HELP
OPTIONS_DEFAULT=PYTHON PRINT HELP
PYTHON_DESC=	Python-fu support
PRINT_DESC=	Gutenprint (gimp-print) plugin
HELP_DESC=	Gimp-Help (50+MB distfile)

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHELP}
RUN_DEPENDS+=	gimp-help*>0:${PORTSDIR}/graphics/gimp-help
.endif

.if ${PORT_OPTIONS:MPYTHON}
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/environ/pygimp.env:${PORTSDIR}/graphics/py-gimp
.endif

.if ${PORT_OPTIONS:MPRINT}
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/plug-ins/gutenprint:${PORTSDIR}/print/gimp-gutenprint
RUN_DEPENDS+=	gutenprint>0:${PORTSDIR}/print/gutenprint
.endif

.include <bsd.port.mk>

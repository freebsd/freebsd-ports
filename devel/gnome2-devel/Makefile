# New ports collection makefile for:	gnome2-devel
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-devel
PORTVERSION=	2.0
CATEGORIES=	devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org

RUN_DEPENDS=	intltool-merge:${PORTSDIR}/textproc/intltool \
		gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon
LIB_DEPENDS=	gnomeprintui-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui \
		gail-gnome.0:${PORTSDIR}/x11-toolkits/libgail-gnome

NO_BUILD=	yes

USE_PYTHON=	yes

do-install:	# empty

.include <bsd.port.mk>

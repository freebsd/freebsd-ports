# New ports collection makefile for:	gnome2-devel
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-devel
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the GNOME 2.0 development API

RUN_DEPENDS=	intltool-merge:${PORTSDIR}/textproc/intltool \
		gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon 

NO_BUILD=	yes
USE_GNOME=	libgnomeprintui gail

USE_PYTHON=	yes

do-install:	# empty

.include <bsd.port.mk>

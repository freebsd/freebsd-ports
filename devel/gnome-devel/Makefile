# New ports collection makefile for:	gnome-devel
# Date created:		23 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-devel
PORTVERSION=	1.4.1b2
CATEGORIES=	devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org

RUN_DEPENDS=	intltool-merge:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	gal:${PORTSDIR}/x11-toolkits/gal \
		gnomemm.9:${PORTSDIR}/x11-toolkits/gnome--

IGNORE=		"Needs more work on the dependency chain"
NO_BUILD=	yes

USE_GNOMENG=	yes
USE_GNOME=	gnomelibs
USE_PYTHON=	yes

do-install:	# empty

.include <bsd.port.mk>

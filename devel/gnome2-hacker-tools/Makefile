# New ports collection makefile for:	gnome2-hacker-tools
# Date created:				07 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-hacker-tools
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 development tools

RUN_DEPENDS=	mlv:${PORTSDIR}/editors/mlview \
		gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon \
		glade-2:${PORTSDIR}/devel/glade2 \
		ghex2:${PORTSDIR}/editors/ghex2 \
		gob2:${PORTSDIR}/devel/gob2 \
		regexxer:${PORTSDIR}/devel/regexxer \
		conglomerate:${PORTSDIR}/editors/conglomerate \
		anjuta:${PORTSDIR}/devel/anjuta \
		meld:${PORTSDIR}/textproc/meld

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>

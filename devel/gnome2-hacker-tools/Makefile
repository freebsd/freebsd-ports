# New ports collection makefile for:	gnome2-hacker-tools
# Date created:				07 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-hacker-tools
PORTVERSION=	2.10.2
CATEGORIES=	devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 development tools

RUN_DEPENDS=	mlview:${PORTSDIR}/editors/mlview \
		gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon \
		glade-2:${PORTSDIR}/devel/glade2 \
		ghex2:${PORTSDIR}/editors/ghex \
		gob2:${PORTSDIR}/devel/gob2 \
		conglomerate:${PORTSDIR}/editors/conglomerate \
		meld:${PORTSDIR}/textproc/meld \
		gtranslator:${PORTSDIR}/devel/gtranslator \
		regexxer:${PORTSDIR}/devel/regexxer \
		anjuta:${PORTSDIR}/devel/anjuta

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>

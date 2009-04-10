# New ports collection makefile for:	gnome2-hacker-tools
# Date created:				07 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gnome2-hacker-tools/Makefile,v 1.47 2009/03/01 08:15:25 marcus Exp $
#

PORTREVISION=	0
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-hacker-tools

COMMENT=	GNOME 2 development tools

RUN_DEPENDS=	mlview:${PORTSDIR}/editors/mlview \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		glade-3:${PORTSDIR}/devel/glade3 \
		ghex2:${PORTSDIR}/editors/ghex \
		gob2:${PORTSDIR}/devel/gob2 \
		conglomerate:${PORTSDIR}/editors/conglomerate \
		meld:${PORTSDIR}/textproc/meld \
		gtranslator:${PORTSDIR}/devel/gtranslator \
		regexxer:${PORTSDIR}/devel/regexxer \
		anjuta:${PORTSDIR}/devel/anjuta \
		accerciser:${PORTSDIR}/accessibility/accerciser \
		valac:${PORTSDIR}/lang/vala

MASTERDIR=	${.CURDIR}/../../x11/gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"

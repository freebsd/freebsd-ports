# New ports collection makefile for:	gnome2-hacker-tools
# Date created:				07 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-hacker-tools
PORTVERSION=	2.5.92
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
		conglomerate:${PORTSDIR}/editors/conglomerate \
		meld:${PORTSDIR}/textproc/meld \
		gtranslator:${PORTSDIR}/devel/gtranslator
# not yet buildable under GNOME 2.5
#		regexxer:${PORTSDIR}/devel/regexxer

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
RUN_DEPENDS+=	anjuta:${PORTSDIR}/devel/anjuta
.endif

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.post.mk>

# New ports collection makefile for:	gnome2-office
# Date created:				07 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/gnome2-office/Makefile,v 1.41 2006/04/12 22:11:33 marcus Exp $
#

PORTREVISION=	0
CATEGORIES=	editors gnome
PKGNAMESUFFIX=	-office

COMMENT=	GNOME 2 office applications

RUN_DEPENDS=	gnumeric:${PORTSDIR}/math/gnumeric \
		planner:${PORTSDIR}/deskutils/planner \
		dia:${PORTSDIR}/graphics/dia \
		glabels:${PORTSDIR}/deskutils/glabels \
		abiword:${PORTSDIR}/editors/abiword
#		mergeant:${PORTSDIR}/databases/mergeant

MASTERDIR=	${.CURDIR}/../../x11/gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"

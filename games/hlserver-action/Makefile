# New ports collection makefile for:	Action Server
# Date created:				Wed Apr 25 11:45:11 SAST 2001
# Whom:					markm@freebsd.org et al
#
# $FreeBSD$
#

PORTNAME=	action
PORTVERSION=	0.5
PORTREVISION=	1
MASTER_SITES=	ftp://ftp.wanadoo.nl/pub/wanadoo/games/HalfLife/Action-Halflife/ \
		ftp://ftp.exp-network.de/hl/mod/ahl/
DISTNAME=	action50

COMMENT=	Action Half-Life mod full server package for Linux
BROKEN=		"Can't fetch file and project went inactive"
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"

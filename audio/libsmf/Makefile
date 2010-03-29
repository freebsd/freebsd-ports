# New ports collection makefile for:	libsmf
# Date created:		2010-03-29
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsmf
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Standard MIDI File format library

LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline

USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAN1=		smfsh.1

.include <bsd.port.mk>

# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsmf
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Standard MIDI File format library

LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline

USES=	pathfix pkgconfig
NO_STAGE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAN1=		smfsh.1

.include <bsd.port.mk>

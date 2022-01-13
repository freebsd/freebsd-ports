# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>

PORTNAME=	jack-smf-utils
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Standard MIDI File file player and recorder for JACK MIDI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack \
		liblash.so:audio/lash

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

CONFLICTS_INSTALL=	libsmf # bin/smfsh

.include <bsd.port.mk>

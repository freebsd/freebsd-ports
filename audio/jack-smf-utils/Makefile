PORTNAME=	jack-smf-utils
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard MIDI File file player and recorder for JACK MIDI
WWW=		https://jack-smf-utils.sourceforge.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack \
		liblash.so:audio/lash

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

USE_GNOME=	glib20

CONFLICTS_INSTALL=	libsmf # bin/smfsh

.include <bsd.port.mk>

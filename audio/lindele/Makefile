# New ports collection makefile for:	lindele
# Date created:			26 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		lindele
PORTVERSION=		0.1.1
PORTREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://download.gna.org/${PORTNAME}/

MAINTAINER=		jylefort@brutele.be
COMMENT=		Yet another simple GNOME music player

RUN_DEPENDS=		musicbox-tag-editor:${PORTSDIR}/audio/musicbox-tag-editor
LIB_DEPENDS=		vorbis:${PORTSDIR}/audio/libvorbis \
			tag:${PORTSDIR}/audio/taglib

USE_X_PREFIX=		yes
USE_REINPLACE=		yes
USE_GNOME=		gnomehack gnomeprefix libgnomeui
USE_GSTREAMER=		gconf
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|musicbox|musicbox-tag-editor|g' \
		${WRKSRC}/src/gui.c \
		${WRKSRC}/src/lindele.c
	@${REINPLACE_CMD} -e 's|@prefix@/share|@datadir@|' \
		${WRKSRC}/data/lindele.glade.in

.include <bsd.port.mk>

# New ports collection makefile for:	MusicBox
# Date created:			26 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		musicbox-tag-editor
PORTVERSION=		0.2.3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	musicbox
DISTNAME=		musicbox-${PORTVERSION}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A simple GTK+ audio tag editor

LIB_DEPENDS=		tag:${PORTSDIR}/audio/taglib

USE_X_PREFIX=		yes
USE_GNOME=		gnomehack gnomeprefix libglade2
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
# do not conflict with audio/musicbox
CONFIGURE_ARGS=		--program-suffix=-tag-editor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps|${PREFIX}/share/gnome/pixmaps|' ${WRKSRC}/data/musicbox.glade
	@${REINPLACE_CMD} -e 's|Exec=musicbox|Exec=musicbox-tag-editor|' ${WRKSRC}/data/musicbox.desktop

.include <bsd.port.mk>

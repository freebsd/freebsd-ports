# New ports collection makefile for:	MusicBox
# Date created:			26 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#   $MCom: ports/audio/musicbox-tag-editor/Makefile,v 1.5 2007/09/10 05:13:24 mezz Exp $
#

PORTNAME=		musicbox-tag-editor
PORTVERSION=		0.2.3
PORTREVISION=	11
CATEGORIES=		audio
MASTER_SITES=		SF/musicbox/musicbox/${PORTVERSION}
DISTNAME=		musicbox-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A simple GTK+ audio tag editor

LIB_DEPENDS=		tag:${PORTSDIR}/audio/taglib

USE_GNOME=		gnomehack gnomeprefix libglade2
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
# do not conflict with audio/musicbox
CONFIGURE_ARGS=		--program-suffix=-tag-editor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps|${PREFIX}/share/pixmaps|' \
		${WRKSRC}/data/musicbox.glade
	@${REINPLACE_CMD} -e 's|Exec=musicbox|Exec=musicbox-tag-editor|' \
		${WRKSRC}/data/musicbox.desktop

.include <bsd.port.mk>

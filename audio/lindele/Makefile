# New ports collection makefile for:	lindele
# Date created:			26 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		lindele
PORTVERSION=		0.1.0
PORTREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://download.gna.org/${PORTNAME}/

MAINTAINER=		jylefort@brutele.be
COMMENT=		Yet another simple GNOME music player

RUN_DEPENDS=		musicbox-tag-editor:${PORTSDIR}/audio/musicbox-tag-editor
LIB_DEPENDS=		vorbis:${PORTSDIR}/audio/libvorbis \
			tag:${PORTSDIR}/audio/taglib

USE_X_PREFIX=		yes
USE_GNOME=		gnomehack gnomeprefix libgnomeui gstreamerplugins
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=			"Does not compile on FreeBSD >= 5.x"
.endif

.include <bsd.port.post.mk>

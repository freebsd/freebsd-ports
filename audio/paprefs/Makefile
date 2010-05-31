# Ports collection Makefile for: paprefs
# Date created:		July 21, 2007
# Whom:			Romain Tartière <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	paprefs
PORTVERSION=	0.9.7
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK configuration dialog for PulseAudio

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gconfmm-2.6.1:${PORTSDIR}/devel/gconfmm26

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intltool

CONFIGURE_ARGS=	--disable-lynx

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>

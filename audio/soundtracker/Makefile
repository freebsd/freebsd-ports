# New ports collection makefile for:   soundtracker
# Date created:        28 November 1999
# Whom:                kzentner
#
# $FreeBSD$
#

PORTNAME=	soundtracker
PORTVERSION=	0.5.3
CATEGORIES=	audio gnome
MASTER_SITES=	ftp://ftp.soundtracker.org/pub/soundtracker/v0.5/

MAINTAINER=	kzentner@u.washington.edu

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

.if defined(USE_GNOME)
LIB_DEPENDS+=	gnome.4:${PORTSDIR}/x11/gnomelibs
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	YES

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

USE_X_PREFIX=	yes

.if defined(USE_GNOME)
CONFIGURE_ARGS+=	--enable-gnome
PLIST=			${PKGDIR}/PLIST.gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"

post-install:
	@strip ${PREFIX}/bin/soundtracker

.include <bsd.port.mk>

# New ports collection makefile for:   soundtracker
# Version required:    0.3.6
# Date created:        28 November 1999
# Whom:                kzentner
#
# $FreeBSD$
#

DISTNAME=	soundtracker-0.3.6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.soundtracker.org/pub/soundtracker/v0.3/

MAINTAINER=	kzentner@u.washington.edu

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	YES

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.if defined(USE_GNOME)
CONFIGURE_ARGS+=	--enable-gnome
.endif

post-install:
	@strip ${PREFIX}/bin/soundtracker

.include <bsd.port.mk>

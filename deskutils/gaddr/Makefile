# New ports collection makefile for:	gaddr
# Version required:		1.1.4.
# Date created:			8 August 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gaddr-1.1.4
CATEGORIES=	deskutils
MASTER_SITES=	http://www.cse.unl.edu/~cluening/gaddr/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.if defined(USE_GNOME)
LIB_DEPENDS+=	gnome.3:${PORTSDIR}/x11/gnomelibs
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.if defined(USE_GNOME)
CONFIGURE_ARGS+= --enable-gnome
.endif

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

post-install:
	@strip ${PREFIX}/bin/gaddr

.include <bsd.port.mk>

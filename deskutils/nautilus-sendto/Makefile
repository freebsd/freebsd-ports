# New ports collection makefile for:	nautilus-sendto
# Date created:		2004-12-03
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-sendto
DISTVERSION=	0.2-1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.es.gnome.org/~telemaco/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integration between nautilus, evolution, and gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net/gaim \
		evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gnometarget nautilus2

# Gnome 2.9 fix
.if exists(${X11BASE}/libdata/pkgconfig/libebook-1.2.pc)
post-patch:
	@${REINPLACE_CMD} -e 's|libebook-1.0|libebook-1.2|' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>

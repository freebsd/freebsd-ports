# New ports collection makefile for:	gnomepim
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepim
PORTVERSION=	1.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-pim
DISTNAME=	gnome-pim-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore

.if defined(WITH_GNOMEPILOT)
LIB_DEPENDS+=	gpilotd.0:${PORTSDIR}/palm/gnomepilot
PILOTINC=	"-I${LOCALBASE}/pilot/include"
PILOTLIB=	"-L${LOCALBASE}/pilot/lib"
.else
PILOTARGS=	--without-pisock --disable-pilotlinktest
EXTRA_PATCHES=	${FILESDIR}/patch.nopilot
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome ${PILOTARGS}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PILOTINC}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib ${PILOTLIB}"

.if !defined(WITH_GNOMEPILOT)
pre-extract:
	@${ECHO} "You can add gnomepilot support by defining WITH_GNOMEPILOT"
.endif

.if defined(WITH_GNOMEPILOT)
post-install:
	@${CAT} ${PKGDIR}/PLIST.pilot >> ${TMPPLIST}
.endif

.include <bsd.port.mk>

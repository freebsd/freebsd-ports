# New ports collection makefile for:	electriceyes
# Version required:			0.3.11
# Date created:				21 August 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	ee-0.3.11
PKGNAME=	electriceyes-0.3.11
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/ee

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
	${MV} ${PREFIX}/bin/ee ${PREFIX}/bin/ElectricEyes

.include <bsd.port.mk>

# New ports collection makefile for:	dryad
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dryad
PORTVERSION=	0.1.3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/dryad

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		glade.3:${PORTSDIR}/devel/libglade \
		oaf.0:${PORTSDIR}/devel/oaf \
		bonobo.2:${PORTSDIR}/devel/bonobo \
		gdf.0:${PORTSDIR}/devel/gnomedebug \
		gnomevfs.0:${PORTSDIR}/devel/gnomevfs
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

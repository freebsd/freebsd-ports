# New ports collection makefile for:	esound
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	esound
PORTVERSION=	0.2.29
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/esound/0.2
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=	esd-config.1 esd.1 esdcat.1 esdctl.1 esddsp.1 esdfilt.1 esdloop.1 \
	esdmon.1 esdplay.1 esdrec.1 esdsample.1

.include <bsd.port.mk>

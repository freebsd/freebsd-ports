# New ports collection makefile for:	libgtop
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop
PORTVERSION=	1.0.9
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libgtop

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		guile.6:${PORTSDIR}/lang/guile

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_PERL5=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
	install-info --section="Programming \& development tools" \
	--entry="* libgtop: (libgtop).	libgtop programming manual" \
	${PREFIX}/info/libgtop.info ${PREFIX}/info/dir

.include <bsd.port.mk>

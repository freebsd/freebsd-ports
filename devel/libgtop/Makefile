# New ports collection makefile for:	libgtop
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtop
PORTVERSION=	1.0.13
PORTREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME top library

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

INFO=		libgtop

.include <bsd.port.mk>

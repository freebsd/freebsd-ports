# New ports collection makefile for:	libglade
# Date created:				18 August 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	0.17
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libglade/0.17

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME glade library

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gnomedb
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-bonobo --enable-gnomedb
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>

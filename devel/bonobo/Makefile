# New ports collection makefile for:	bonobo
# Date created:				8th October 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	bonobo
PORTVERSION=	1.0.22
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The component and compound document system for GNOME

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix oaf gnomehier gnomeprint
GNOME_HTML_DIR=	${PREFIX}/share/doc/bonobo
INSTALLS_SHLIB=	yes
#USE_LIBTOOL=	yes
#LIBTOOLFILES=	configure libefs/configure
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>

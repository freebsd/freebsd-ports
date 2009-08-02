# New ports collection makefile for:	libgda
# Date created:				8th March 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda/Makefile,v 1.5 2007/05/19 21:36:00 marcus Exp $
#

PORTNAME=	libgda
PORTVERSION=	0.2.96
PORTREVISION=	11
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides uniform access to different kinds of data sources

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

CONFLICTS=	libgda2*-[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gconf bonobo
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl -lgdbm"
PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>

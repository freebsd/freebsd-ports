# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda/Makefile,v 1.5 2007/05/19 21:36:00 marcus Exp $

PORTNAME=	libgda
PORTVERSION=	0.2.96
PORTREVISION=	16
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides uniform access to different kinds of data sources

LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm

CONFLICTS=	libgda2*-[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gconf bonobo
USE_GMAKE=	yes
USES=		gettext
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl -lgdbm"
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB=	VERSION=${PORTVERSION}
MAKE_JOBS_UNSAFE=yes

NO_STAGE=	yes
.include <bsd.port.mk>

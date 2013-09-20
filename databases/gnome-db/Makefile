# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/gnome-db/Makefile,v 1.5 2007/05/19 21:36:00 marcus Exp $

PORTNAME=	gnome-db
PORTVERSION=	0.2.96
PORTREVISION=	15
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provide uniform access to data sources for the GNOME environment

USE_BZIP2=	yes
USE_GCC=	any
USE_GNOME=	gnomehack gnomeprefix gnomehier libgda
USE_GMAKE=	yes
USES=		gettext
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -lintl"
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB=	VERSION=${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/gnomedb

NO_STAGE=	yes
.include <bsd.port.mk>

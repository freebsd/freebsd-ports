# New ports collection makefile for:	gnomedb
# Date created:				19th June 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/gnome-db/Makefile,v 1.5 2007/05/19 21:36:00 marcus Exp $
#

PORTNAME=	gnome-db
PORTVERSION=	0.2.96
PORTREVISION=	11
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provide uniform access to data sources for the GNOME environment

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier libgda
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -lintl"
PLIST_SUB=	VERSION=${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/gnomedb

.include <bsd.port.mk>

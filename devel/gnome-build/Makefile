# New ports collection makefile for:	gnomebuild
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebuild
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/gnome/gnome-/}/0.1
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	A GNOME Build Framework (GBF)

LIB_DEPENDS=	gdl-1.0:${PORTSDIR}/x11-toolkits/gdl

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libgnomeui gnomevfs2
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

.include <bsd.port.mk>

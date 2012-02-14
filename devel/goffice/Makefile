# New ports collection makefile for:	goffice
# Date created:				07 June 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/devel/goffice/Makefile,v 1.3 2010/06/29 10:56:38 kwm Exp $
#
# !!! When updating goffice, don't forget to update pkg-plist in:
#     math/gnumeric science/gchemutils

PORTNAME=	goffice
PORTVERSION=	0.8.17
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 libgsf ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION=${PORTVERSION} \
		SHORT_VER=0.8

MAKE_JOBS_SAFE=	yes

.if !defined(WITHOUT_GCONF)
USE_GNOME+=	gconf2
.else
CONFIGURE_ARGS+=--with-config-backend=keyfile
.endif

.include <bsd.port.mk>

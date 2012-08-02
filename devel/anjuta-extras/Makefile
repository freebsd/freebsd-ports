# New ports collection makefile for:	anjuta-extras
# Date created:				8 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/anjuta-extras/Makefile,v 1.11 2010/09/29 12:14:23 kwm Exp $
#

PORTNAME=	anjuta-extras
PORTVERSION=	2.32.1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extra anjuta plugins

LIB_DEPENDS=	anjuta.0:${PORTSDIR}/devel/anjuta
		
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--disable-plugin-valgrind \
		--localedir=${PREFIX}/share

GCONF_SCHEMAS=	anjuta-editor-scintilla.schemas

.include <bsd.port.mk>

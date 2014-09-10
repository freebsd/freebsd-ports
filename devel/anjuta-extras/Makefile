# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/anjuta-extras/Makefile,v 1.11 2010/09/29 12:14:23 kwm Exp $

PORTNAME=	anjuta-extras
PORTVERSION=	2.32.1.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extra anjuta plugins

LIB_DEPENDS=	libanjuta.so:${PORTSDIR}/devel/anjuta
		
USES=		gmake libtool:keepla tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	intltool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--disable-plugin-valgrind \
		--localedir=${PREFIX}/share

GCONF_SCHEMAS=	anjuta-editor-scintilla.schemas

.include <bsd.port.mk>

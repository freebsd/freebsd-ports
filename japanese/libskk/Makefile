# New ports collection makefile for:	libskk
# Date created:	21 December 2011
# Whom:		Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libskk
PORTVERSION=	0.0.9
CATEGORIES=	japanese
MASTER_SITES=	http://cloud.github.com/downloads/ueno/libskk/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	A library to deal with Japanese kana-to-kanji conversion method

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gee.2:${PORTSDIR}/devel/libgee \
		json-glib-1.0.0:${PORTSDIR}/devel/json-glib

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
MAN1=		skk.1

CPPFLAGS+=	-I${LOCALBASE}/include

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	cd ${WRKSRC}/docs && ${GMAKE} install-man

.include <bsd.port.mk>

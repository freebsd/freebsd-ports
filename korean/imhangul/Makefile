# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	imhangul
PORTVERSION=	${GTKVER}.1.1
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	GTK+ Hangul input module

LICENSE=	GPLv2

LIB_DEPENDS=	hangul:${PORTSDIR}/korean/libhangul

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:bzip2

OPTIONS_DEFINE=	GTK3 NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME=	gtk30
GTKVER=	3
PLIST_SUB=	GTK2="@comment " GTK3=""
.else
USE_GNOME=	gtk20
GTKVER=	2
PLIST_SUB=	GTK2="" GTK3="@comment "
.endif
PLIST_SUB+=	GTKVER="${GTKVER}.0"

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>

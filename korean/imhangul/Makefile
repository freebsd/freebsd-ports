# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	imhangul
PORTVERSION=	${GTKVER}.1.1
PORTREVISION=	2
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	GTK+ Hangul input module

LICENSE=	GPLv2

LIB_DEPENDS=	libhangul.so:korean/libhangul

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	GTKVER=${GTKVER}.0
USE_GNOME=	gtk${GTKVER}0
USES=		gmake libtool pkgconfig tar:bzip2

OPTIONS_DEFINE=	GTK3 NLS
OPTIONS_SUB=	yes

GTK3_VARS=	GTKVER=3
GTK3_VARS_OFF=	GTKVER=2

NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib
NLS_USES=	gettext

.include <bsd.port.mk>

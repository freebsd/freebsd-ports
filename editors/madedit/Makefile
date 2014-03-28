# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madedit
PORTVERSION=	0.2.9
PORTREVISION=	10
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/MadEdit/MadEdit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source and cross-platform text/hex editor

LICENSE=	GPLv2

USES=		gettext pkgconfig dos2unix desktop-file-utils
USE_WX=		2.8+
WANT_UNICODE=	yes

LIB_DEPENDS+=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-wx-config=${WX_CONFIG}
CONFIGURE_ENV+=	PKG_CONFIG="${PKG_CONFIG}" glib_gtk2_CFLAGS="${glib_gtk2_CFLAGS}" glib_gtk2_LIBS="${glib_gtk2_LIBS}"
CXXFLAGS+=	${glib_gtk2_CFLAGS}

PKG_CONFIG?=	${LOCALBASE}/bin/pkgconf
glib_gtk2_CFLAGS=`${PKG_CONFIG} --cflags gtk+-2.0`
glib_gtk2_LIBS=	`${PKG_CONFIG} --libs gtk+-2.0`

BROKEN_sparc64=	yes

.include <bsd.port.mk>

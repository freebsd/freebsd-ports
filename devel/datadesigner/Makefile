# ex:ts=8
# Ports collection makefile for:	datadesigner
# Date created:			Jul 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	datadesigner
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.danny.cz/
MASTER_SITE_SUBDIR=	dbdesign

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database Schema Designer

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

USE_GNOME=	libxml2 libxslt
USE_ICONV=	yes
GNU_CONFIGURE=	yes
WX_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>

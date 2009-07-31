# New ports collection makefile for:	epsilon
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	epsilon
PORTVERSION=	0.3.0.012
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A small, display independent and quick thumbnailing library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget
USE_EFL=	edje imlib2 ecore
USE_EFL_ECORE=	file ipc
USE_LDCONFIG=	yes

OPTIONS=	PNG	"Enable PNG thumbnailer" on \
		EPEG	"Enable Epeg thumbnailer" on \
		XINE	"Enable Xine thumbnailer" off

.include <bsd.port.pre.mk>

.if defined(WITH_PNG) || exists(${LOCALBASE}/lib/libpng.so.5)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
PLIST_SUB+=	PNG="@comment "
.endif

.if defined(WITH_EPEG) || exists(${LOCALBASE}/lib/libepeg.so.9)
USE_EFL+=	epeg
PLIST_SUB+=	EPEG=""
.else
PLIST_SUB+=	EPEG="@comment "
.endif

.if defined(WITH_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--enable-thumbnailer-xine
PLIST_SUB+=	XINE=""
.else
CONFIGURE_ARGS+=--disable-thumbnailer-xine
PLIST_SUB+=	XINE="@comment "
.endif

.include <bsd.port.post.mk>

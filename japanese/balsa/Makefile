# New ports collection makefile for:	ja-balsa
# Date created:				02 Mar 2000
# Whom:					Yoichi ASAI <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION=	0.8.0
CATEGORIES=	japanese mail gnome
MASTER_SITES=	ftp://ftp.critical.ne.jp/pub/balsa-ja/
DISTNAME=	balsa-0.8.0-ja

MAINTAINER=	yatt@msc.biglobe.ne.jp

RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		PropList.2:${PORTSDIR}/devel/libPropList

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ENV=	GTK_CONFIG='${GTK_CONFIG}' \
		GLIB_CONFIG='${GLIB_CONFIG}' \
		CPPFLAGS='-I${LOCALBASE}/include' \
		LIBS='-L${LOCALBASE}/lib'
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX} \
		--enable-system-install --enable-threads
WRKSRC=		${WRKDIR}/balsa-0.8.0ja

MAN1=		balsa.1

pre-configure:
	${RM} ${WRKSRC}/config.cache ${WRKSRC}/libmutt/config.cache

post-install:
	${INSTALL_MAN} ${WRKSRC}/balsa.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

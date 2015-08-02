# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgtop/Makefile 19959 2014-10-15 14:06:28Z kwm $

PORTNAME=	libgtop
PORTVERSION=	2.30.0
PORTREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

USE_PERL5=	build
USE_XORG=	xau
USES=		gettext gmake libtool makeinfo pathfix perl5 pkgconfig tar:xz
USE_GNOME=	gnomeprefix glib20 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lutil
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection

INFO=		libgtop2

PKGMESSAGE=	${FILESDIR}/pkg-message

.include <bsd.port.mk>

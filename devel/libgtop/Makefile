# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgtop/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libgtop
PORTVERSION=	2.30.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

USE_PERL5=	build
USE_XORG=	xau
USES=		gettext gmake libtool pathfix perl5 pkgconfig tar:xz
USE_GNOME=	gnomeprefix glib20 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_NET_IF_VAR_H -D_WANT_IFADDR
LDFLAGS+=	-L${LOCALBASE}/lib -lutil
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection

INFO=		libgtop2

PKGMESSAGE=	${FILESDIR}/pkg-message

post-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.include <bsd.port.mk>

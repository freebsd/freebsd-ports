# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgtop/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgtop
PORTVERSION=	2.28.4
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

USE_PERL5=	build
USE_XORG=	xau
USES=		gettext gmake libtool pathfix perl5 pkgconfig tar:xz
USE_GNOME=	gnomeprefix glib20 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_NET_IF_VAR_H -D_WANT_IFADDR
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-introspection

INFO=		libgtop2

PKGMESSAGE=	${FILESDIR}/pkg-message

post-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.include <bsd.port.mk>

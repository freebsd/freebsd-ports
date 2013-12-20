# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgtop/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libgtop
PORTVERSION=	2.28.5
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

USE_XZ=		yes
USE_PERL5=	build
USE_XORG=	xau
USES=		gettext gmake pathfix perl5 pkgconfig
USE_GNOME=	gnomeprefix glib20 ltverhack intlhack introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_NET_IF_VAR_H -D_WANT_IFADDR
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-introspection

INFO=		libgtop2

PKGMESSAGE=	${FILESDIR}/pkg-message

post-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtop-2.0.so.7

.include <bsd.port.mk>

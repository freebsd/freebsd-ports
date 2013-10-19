# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgtop/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgtop
PORTVERSION=	2.28.4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 top library

USE_XZ=		yes
USE_PERL5=	build
USE_XORG=	xau
USES=		gettext gmake pathfix pkgconfig perl5
USE_GNOME=	gnomeprefix glib20 ltverhack intlhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_NET_IF_VAR_H -D_WANT_IFADDR
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-introspection

INFO=		libgtop2

PKGMESSAGE=	${FILESDIR}/pkg-message

NO_STAGE=	yes
post-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

post-install:
	@${CHGRP} kmem ${PREFIX}/bin/libgtop_server2
	@${CHMOD} 2555 ${PREFIX}/bin/libgtop_server2
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

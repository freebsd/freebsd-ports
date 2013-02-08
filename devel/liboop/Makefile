# Created by: ijliao
# $FreeBSD$

PORTNAME=	liboop
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	GENTOO/distfiles \
		http://download.ofb.net/liboop/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	A low-level event loop management library for POSIX-based OS

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns \
		wwwcore.1:${PORTSDIR}/www/libwww

USE_BZIP2=	yes
USE_GNOME=	glib12 glib20 gnomehack
USE_TCL_BUILD=	yes
USE_TCL=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-libwww
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${TCL_INCLUDEDIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|8\.4|${TCL_VER:S/.//}|g' ${WRKSRC}/configure

.include <bsd.port.mk>

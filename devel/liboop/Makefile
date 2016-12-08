# Created by: ijliao
# $FreeBSD$

PORTNAME=	liboop
PORTVERSION=	1.0
PORTREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	GENTOO \
		http://download.ofb.net/liboop/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Low-level event loop management library for POSIX-based OS

LICENSE=	GPLv2

LIB_DEPENDS=	libadns.so:dns/adns \
		libwwwcore.so:www/libwww

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libwww
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
MAKE_JOBS_UNSAFE=	yes
USE_GNOME=	glib12 glib20
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig tcl tar:bzip2

CPPFLAGS+=	-I${TCL_INCLUDEDIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|8\.4|${TCL_VER:S/.//}|g' ${WRKSRC}/configure

.include <bsd.port.mk>

# Created by: ijliao
# $FreeBSD$

PORTNAME=	liboop
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	GENTOO/distfiles \
		http://download.ofb.net/liboop/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Low-level event loop management library for POSIX-based OS

LICENSE=	GPLv2

LIB_DEPENDS=	libadns.so:${PORTSDIR}/dns/adns \
		libwwwcore.so:${PORTSDIR}/www/libwww

CONFIGURE_ARGS=	--with-libwww
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
MAKE_JOBS_UNSAFE=	yes
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GNOME=	glib12 glib20
USE_LDCONFIG=	yes
USES=		pathfix tcl

CPPFLAGS+=	-I${TCL_INCLUDEDIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|8\.4|${TCL_VER:S/.//}|g' ${WRKSRC}/configure

.include <bsd.port.mk>

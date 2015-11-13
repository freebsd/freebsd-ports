# $FreeBSD$

# NOTE: comms/xcwcp is a sub-port of this.  When making changes, ensure
#       it still works as well.

PORTNAME?=	unixcw
PORTVERSION=	3.5.0
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/unixcw/unixcw-${PORTVERSION}
DISTNAME=	unixcw_${PORTVERSION}.orig

MAINTAINER=	hamradio@FreeBSD.org
COMMENT?=	Libs for cw on unix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
.ifndef	CONFIGURE_ARGS
CONFIGURE_ARGS=	--disable-xcwcp
.endif
CONFIGURE_ARGS+=	--includedir="${LOCALBASE}/include" \
			--libdir="${LOCALBASE}/lib" \
			--disable-alsa --disable-pulseaudio

USE_LDCONFIG=	yes
USES+=		gmake libtool pkgconfig
USE_CSTD=	gnu99
WRKSRC=		${WRKDIR}/unixcw-${PORTVERSION}
MAJOR_LIB_VER=	6
MINOR_LIB_VER=	5.1
PLIST_SUB=	MAJOR_LIB_VER=${MAJOR_LIB_VER}
PLIST_SUB+=	MINOR_LIB_VER=${MINOR_LIB_VER}

post-install:
.ifndef XCWCP
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcw.so.${MAJOR_LIB_VER}.${MINOR_LIB_VER}
.endif

.include <bsd.port.mk>

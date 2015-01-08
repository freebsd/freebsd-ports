# $FreeBSD$

# NOTE: comms/xcwcp is a sub-port of this.  When making changes, ensure
#       it still works as well.

PORTNAME?=	unixcw
PORTVERSION=	3.4.1
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/unixcw/unixcw-${PORTVERSION}
DISTNAME=	unixcw_${PORTVERSION}.orig

MAINTAINER=	hamradio@FreeBSD.org
COMMENT?=	Libs for cw on unix

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
.ifndef CONFIGURE_ARGS
CONFIGURE_ARGS=	--disable-xcwcp
.endif
CONFIGURE_ARGS+=	--includedir="${LOCALBASE}/include" \
			--libdir="${LOCALBASE}/lib" \
			--disable-alsa --disable-pulseaudio

USE_LDCONFIG=	yes
USES=		gmake libtool pkgconfig
USE_CSTD=	gnu99
WRKSRC=		${WRKDIR}/unixcw-${PORTVERSION}

post-install:
	  ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcw.so.6.3.1

.include <bsd.port.mk>

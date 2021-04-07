# NOTE: comms/xcwcp is a sub-port of this.  When making changes, ensure
#       it still works as well.

PORTNAME?=	unixcw
PORTVERSION=	3.5.1
PORTREVISION?=	1
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
			--libdir="${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
#CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib CPPFLAGS=-I${LOCALBASE}/include

USES+=		gmake libtool ncurses pathfix pkgconfig autoreconf
USE_LDCONFIG=	yes
USE_CSTD=	gnu99
WRKSRC=		${WRKDIR}/unixcw-${PORTVERSION}
MAJOR_LIB_VER=	6
MINOR_LIB_VER=	6.1
PLIST_SUB=	MAJOR_LIB_VER=${MAJOR_LIB_VER}
PLIST_SUB+=	MINOR_LIB_VER=${MINOR_LIB_VER}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.ifndef XCWCP
OPTIONS_DEFINE+=	ALSA PULSEAUDIO
OPTIONS_DEFAULT+=	ALSA PULSEAUDIO
ALSA_CONFIGURE_ENABLE=	alsa
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio
ALSA_BUILD_DEPENDS=	${LOCALBASE}/include/alsa/asoundlib.h:audio/alsa-lib
PULSEAUDIO_BUILD_DEPENDS=	${LOCALBASE}/include/pulse/simple.h:audio/pulseaudio
.endif

post-install:
.ifndef XCWCP
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcw.so.${MAJOR_LIB_VER}.${MINOR_LIB_VER}
.endif

.include <bsd.port.mk>

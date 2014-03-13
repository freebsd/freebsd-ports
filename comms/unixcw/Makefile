# $FreeBSD$

PORTNAME=	unixcw
PORTVERSION=	3.3.0
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	unixcw_3.3.0.orig

MAINTAINER=	db@FreeBSD.org
COMMENT=	Libs for cw on unix

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--includedir="${LOCALBASE}/include" \
			--libdir="${LOCALBASE}/lib" \
			--disable-alsa --disable-pulseaudio

.if defined(WITH_XCWCP)
USE_QT4=	gui moc_build qmake_build rcc_build uic_build designer
USE_AUTOTOOLS=	autoconf
PLIST_SUB+=	XCWCP=""
CONFIGURE_ARGS+=	--enable-xcwcp
.else
PLIST_SUB+=	XCWCP="@comment "
CONFIGURE_ARGS+=	--disable-xcwcp
.endif
USE_LDCONFIG=	yes
USES=		gmake
USE_CSTD=	gnu99
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-extract:
.if !defined(WITH_XCWCP)
	@${ECHO_CMD}
	@${ECHO_CMD} "****** To build xcwcp, interrupt the build  ******"
	@${ECHO_CMD} "****** now, set WITH_XCWCP and start again. ******"
	@${ECHO_CMD}
	@sleep 3
.endif

.include <bsd.port.mk>

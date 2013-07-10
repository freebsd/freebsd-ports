# $FreeBSD$

PORTNAME=	mednafen
PORTVERSION=	0.8.B
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	emulators games
MASTER_SITES=	SF/${PORTNAME}/Mednafen/${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable multi-system emulator

LIB_DEPENDS=	cdio.13:${PORTSDIR}/sysutils/libcdio \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.4:${PORTSDIR}/audio/libvorbis

MAKE_JOBS_UNSAFE=	yes
USES=		gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl net
USE_XORG=	x11
USE_GL=		glut
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}
WRKSRC=	${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
FLAG_NLS=	true
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${ARCH}==sparc64
BROKEN=		does not compile on ${ARCH} due to internal compiler error
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' -e \
		's|/usr/local|${LOCALBASE}|g' -e 's|/usr/X11R6|${LOCALBASE}|g' \
			${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Documentation/mednafen.html ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

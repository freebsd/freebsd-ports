# New ports collection makefile for:	mednafen
# Date created:		2006-02-28
# Whom:			Charlie & <root@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	mednafen
PORTVERSION=	0.7.1
CATEGORIES=	emulators games
MASTER_SITES=	SF

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable multi-system emulator

LIB_DEPENDS=	cdio.7:${PORTSDIR}/sysutils/libcdio \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl net
USE_GL=		yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
WRKSRC=	${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS=	NLS	"Native Language Support"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
FLAG_NLS=	true
.endif

.if ${ARCH}==sparc64
BROKEN=		does not compile on ${ARCH} due to internal compiler error
.endif

.if ${OSVERSION} < 503000
IGNORE=		needs round(3), which appears in 5.3 or later
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Documentation/mednafen.html ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

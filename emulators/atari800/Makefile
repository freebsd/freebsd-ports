# Created by: Joel Sutton <jsutton@webnet.com.au>
# $FreeBSD$

PORTNAME=	atari800
PORTVERSION=	3.1.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftpmirror.uk/freebsd-ports/atari800/ \
		SF/${PORTNAME}/ROM/Original%20XL%20ROM:x \
		ftp://ftpmirror.uk/freebsd-ports/atari800/:x
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xf25.zip:x
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Atari 8-bit computer emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	${UNZIP_CMD}:archivers/unzip
LIB_DEPENDS=	libpng.so:graphics/png

RESTRICTED=	xf25 contains copyright ROMs and cannot be distributed.

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USES=		gmake
GNU_CONFIGURE=	yes
NO_OPTIONS_SORT=yes

OPTIONS_DEFINE=	DOCS SHM SDL SERIOSOUND CLIPSOUND PAGEDATTRIB BUFFEREDLOG VERYSLOW
OPTIONS_DEFAULT=	SHM

SHM_DESC=	X11 frontend with shared memory extensions
SDL_DESC=	SDL frontend
SERIOSOUND_DESC=Serial in/out sound
CLIPSOUND_DESC=	Sound clipping
PAGEDATTRIB_DESC=Page-based attribute array
BUFFEREDLOG_DESC=Buffered debug output (until graphics mode switches back to text mode)
VERYSLOW_DESC=	Very slow computer support

CFLAGS+=	-I${LOCALBASE}/include/libpng
LDFLAGS+=	-L${LOCALBASE}/lib

ATARI_XF=	ataribas.rom atariosb.rom atarixl.rom demos1.xfd \
		demos2.xfd dos25.xfd mydos45d.atr

SERIOSOUND_CONFIGURE_ON=	--enable-seriosound
CLIPSOUND_CONFIGURE_ON=	--enable-cripsound
PAGEDATTRIB_CONFIGURE_ON=	--enable-pagedattrib
BUFFEREDLOG_CONFIGURE_ON=	--enable-bufferedlog
VERYSLOW_CONFIGURE_ON=	--enable-veryslow

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
PKGNAMESUFFIX=	-sdl
USE_SDL=	sdl
CONFIGURE_ARGS+=	--target=sdl
.else
USES+=		xorg
USE_XORG=	x11 xext
.if ${PORT_OPTIONS:MSHM}
CONFIGURE_ARGS+=	--target=x11-shm
.else
CONFIGURE_ARGS+=	--target=x11
.endif
.endif

post-patch:
	@${CP} ${FILESDIR}/atari800.cfg ${WRKSRC}
	@${REINPLACE_CMD} -e 's|GUMBY|${DATADIR}|g' ${WRKSRC}/atari800.cfg
	@${REINPLACE_CMD} -e 's|/etc|${DATADIR}|g' ${WRKSRC}/cfg.c
	@${REINPLACE_CMD} -e 's|/etc|${DATADIR}|g' ${WRKSRC}/atari.c
	@${REINPLACE_CMD} -e 's|sdl-config|$$SDL_CONFIG|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${UNZIP_CMD} -q -L -o ${DISTDIR}/${DIST_SUBDIR}/xf25.zip ${ATARI_XF} -d ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atari800 ${STAGEDIR}${PREFIX}/bin/atari800
	${INSTALL_MAN} ${WRKSRC}/atari800.man ${STAGEDIR}${MANPREFIX}/man/man1/atari800.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/atari800.cfg ${STAGEDIR}${DATADIR}
.for rom in ${ATARI_XF}
	${INSTALL_DATA} ${WRKSRC}/${rom} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in BUGS CHANGES.OLD CREDITS ChangeLog FAQ README TODO USAGE
	${INSTALL_DATA} ${WRKSRC}/../DOC/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:   Atari800
# Date created:		29th April, 1997
# Whom:			Joel Sutton <jsutton@webnet.com.au>
#
# $FreeBSD$
#

PORTNAME=	atari800
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xf25.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari 8-bit computer emulator

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	"xf25 contains copyright ROMs and cannot be distributed."

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		atari800.1

ATARI_XF=	ataribas.rom atariosb.rom atarixl.rom demos1.xfd \
		demos2.xfd dos25.xfd mydos45d.atr

.if defined(WITH_SDL)
PKGNAMESUFFIX=	-sdl
USE_SDL=	yes
CONFIGURE_ARGS+=	--target=sdl
.else
USE_XLIB=	yes
.if defined(WITHOUT_SHM)
CONFIGURE_ARGS+=	--target=x11
.else
CONFIGURE_ARGS+=	--target=shm
.endif
.endif

.if defined(WITH_SERIOSOUND)
CONFIGURE_ARGS+=	--enable-seriosound
.endif

.if defined(WITH_CLIPSOUND)
CONFIGURE_ARGS+=	--enable-cripsound
.endif

.if defined(WITH_SNAILMETER)
CONFIGURE_ARGS+=	--enable-snailmeter
.endif

.if defined(WITH_PAGEDATTRIB)
CONFIGURE_ARGS+=	--enable-pagedattrib
.endif

.if defined(WITH_BUFFERDLOG)
CONFIGURE_ARGS+=	--enable-bufferdlog
.endif

.if defined(WITH_DISKLED)
CONFIGURE_ARGS+=	--enable-diskled
.endif

.if defined(WITH_VERYSLOW)
CONFIGURE_ARGS+=	--enable-veryslow
.endif

.if defined(WITH_CURSORBLOCK)
CONFIGURE_ARGS+=	--enable-cursorblock
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Atari800 has the following tunable option(s):"
	@${ECHO_MSG} "	WITHOUT_SHM=yes		Use X11 frontend without shared memory extensions"
	@${ECHO_MSG} "	WITH_SDL=yes		Use SDL frontend"
	@${ECHO_MSG} "	WITH_SERIOSOUND=yes	Use serial in/out sound"
	@${ECHO_MSG} "	WITH_CLIPSOUND=yes	Use bufferd debug output"
	@${ECHO_MSG} "	WITH_SNAILMETER=yes	Show how much the emulator is slower than the original"
	@${ECHO_MSG} "	WITH_PAGEDATTRIB=yes	Use page-based attribute array"
	@${ECHO_MSG} "	WITH_BUFFERDLOG=yes	Use buffered debug output"
	@${ECHO_MSG} "				(until the graphics mode switches back to text mode)"
	@${ECHO_MSG} "	WITH_DISKLED=yes	Show disk LED emulation on screen display"
	@${ECHO_MSG} "	WITH_VERYSLOW=yes	Use very slow computer support"
	@${ECHO_MSG} "				(disables generating screen completely)"
	@${ECHO_MSG} "	WITH_CURSORBLOCK=yes	Using cursor/ctrl keys for keyboard joystick"
	@${ECHO_MSG} ""

post-patch:
	@${CP} ${FILESDIR}/atari800.cfg ${WRKSRC}
	@${REINPLACE_CMD} -e 's|GUMBY|${DATADIR}|g' ${WRKSRC}/atari800.cfg
	@${REINPLACE_CMD} -e 's|/etc|${DATADIR}|g' ${WRKSRC}/rt-config.c
	@${REINPLACE_CMD} -e 's|tmpnam|mkstemp|g' ${WRKSRC}/devices.c \
		${WRKSRC}/compfile.c
	@${REINPLACE_CMD} -e 's|sdl-config|$$SDL_CONFIG|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@unzip -q -L -o ${DISTDIR}/${DIST_SUBDIR}/xf25.zip ${ATARI_XF} -d ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atari800 ${PREFIX}/bin/atari800
	${INSTALL_MAN} ${WRKSRC}/atari800.man ${MANPREFIX}/man/man1/atari800.1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/atari800.cfg ${DATADIR}
.for file in ${ATARI_XF}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES.OLD CREDITS ChangeLog FAQ INSTALL README TODO USAGE
	${INSTALL_DATA} ${WRKSRC}/../DOC/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

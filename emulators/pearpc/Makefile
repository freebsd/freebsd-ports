# New ports collection makefile for:	pearpc
# Date created:				22 May 2004
# Whom:					Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	pearpc
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

MAINTAINER=	novel@FreeBSD.org
COMMENT=	PowerPC emulator

GNU_CONFIGURE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_XORG=	x11
MAN1=		ppc.1

PLIST_FILES=	bin/ppc etc/ppccfg.example %%DATADIR%%/video.x
PLIST_DIRS=	%%DATADIR%%

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.else
CONFIGURE_ARGS+=	--disable-fpo
.endif

# GTK and QT ui are broken in this version
#
#.if defined(WITH_QT)
#CONFIGURE_ARGS+=	--enable-ui=qt
#USE_QT_VER=	3
#QTDIR?=		${QT_PREFIX}
#CONFIGURE_ENV+=	QTDIR="${QTDIR}"
#.else
#CONFIGURE_ARGS+=	--enable-ui=nogui
#.endif

.if defined(WITH_SDL)
CONFIGURE_ARGS+=	--enable-ui=sdl
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=	--enable-ui=x11
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=			Internal compiler error on ia64
.endif

# jitc_x86 is avaible only on x86
.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.if !defined(WITH_JITC)
CONFIGURE_ARGS+=	--enable-cpu=generic
.else
CONFIGURE_ARGS+=	--enable-cpu=jitc_x86
.endif # WITH_JITC
.else
CONFIGURE_ARGS+=	--enable-cpu=generic
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can do optimized build defining WITH_OPTIMIZED_CFLAGS=yes."
	@${ECHO_MSG} ""
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|-g -O2||;s|-O2||' ${WRKSRC}/configure

pre-configure:
.if ${OSVERSION} > 700000
	@${REINPLACE_CMD} -e 's|clock_settime\ ()|foobar()|' ${WRKSRC}/configure
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/src/Makefile

post-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/video.x ${DATADIR}/video.x
	@${SED} -e 's,PREFIX,${PREFIX},g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${PREFIX}/etc/ppccfg.example

.include <bsd.port.post.mk>

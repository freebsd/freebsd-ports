# New ports collection makefile for:	pearpc
# Date created:				22 May 2004
# Whom:					Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	pearpc
PORTVERSION=	0.3.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	PowerPC emulator

USE_XLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=       --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PKGMESSAGE=	${WRKDIR}/pkg-message

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
#QTDIR?=		${X11BASE}
#CONFIGURE_ENV+=	QTDIR="${QTDIR}"
#.else
#CONFIGURE_ARGS+=	--enable-ui=nogui
#.endif

.include <bsd.port.pre.mk>

# jitc_x86 is avaible only on x86
.if ${ARCH} == "i386"
.if !defined(WITH_JITC)
CONFIGURE_ARGS+=	--enable-cpu=generic
.else
CONFIGURE_ARGS+=	--enable-cpu=jitc_x86
.endif # WITH_JITC
.else
CONFIGURE_ARGS+=	--enable-cpu=generic
.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.3
CFLAGS+=	-DFREEBSD_MB_SUPPORT
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can do optimized build defining WITH_OPTIMIZED_CFLAGS=yes."
	@${ECHO_MSG} ""
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/src/system/osapi/posix/types.h
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/src/Makefile
.if ${OSVERSION} < 500000
	@${CP} ${FILESDIR}/wcrtomb.c ${FILESDIR}/mbrtowc.c \
		${WRKSRC}/
.endif

post-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/video.x ${DATADIR}/video.x
	@${SED} -e 's,PREFIX,${PREFIX},g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${PREFIX}/etc/ppccfg.example

.include <bsd.port.post.mk>

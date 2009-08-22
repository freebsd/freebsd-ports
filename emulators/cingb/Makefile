# New ports collection makefile for:   cingb
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cingb
PORTVERSION=	0.29
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/V029A

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Nintendo GameBoy(tm) emulator

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11 xext
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	standard

PORTDOCS=	README README.FAQ
PLIST_FILES=	bin/cingb bin/cingb_conf

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "powerpc"
CPPFLAGS+=	-DUSE_LITTLE_ENDIAN
.endif

do-configure:
	cd ${WRKSRC} && ${SED} -e \
		's|gcc|$${CC}|g ; \
		 s|/usr/X11R6|$${LOCALBASE}|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^OPTMZ|#OPTMZ|g ; \
		 s|%%%endian%%%|$${CPPFLAGS}|g ; \
		 s|%%%pthread%%%|$${LDFLAGS}|g ; \
		 s|%%%libext%%%|-lXext|g ; \
		 s|%%%libsocket%%%||g ; \
		 s|%%%libnsl%%%||g ; \
		 s|%%%joystick%%%|-DBSD_JOYSTICK|g ; \
		 s|%%%framebuffer%%%||g ; \
		 s|%%%mitshm%%%|-DMIT_SHM|g ; \
		 s|%%%sound%%%|-DSOUND|g ; \
		 s|%%%joyconf%%%|conf|g' < Makefile.templ > Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cingb ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cingb_conf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FAQ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

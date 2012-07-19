# New ports collection makefile for:   cingb
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cingb
PORTVERSION=	0.31
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Nintendo GameBoy(tm) emulator

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USE_XORG=	x11 xext xv
MAKE_ENV=	X11BASE="${LOCALBASE}"
ALL_TARGET=	standard
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README README.FAQ
PLIST_FILES=	bin/cingb bin/cingb_conf

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "powerpc"
CPPFLAGS+=	-DUSE_LITTLE_ENDIAN
.endif

do-configure:
	cd ${WRKSRC} && ${SED} -e \
		's|%%%endian%%%|$${CPPFLAGS}|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|%%%prefix-setup%%%||g ; \
		 s|-I/usr/include -I/usr/include/glide||g ; \
		 s|-I/usr/include/X11||g ; \
		 s|%%%pthread%%%|$${LDFLAGS}|g ; \
		 s|%%%libext%%%|-lXext|g ; \
		 s|%%%libsocket%%%||g ; \
		 s|%%%libnsl%%%||g ; \
		 s|%%%LIBXV%%%|-lXv|g ; \
		 s|^OPTMZ|#OPTMZ|g ; \
		 s|%%%joystick%%%|-DBSD_JOYSTICK|g ; \
		 s|%%%framebuffer%%%||g ; \
		 s|%%%mitshm%%%|-DMIT_SHM|g ; \
		 s|%%%XVDEF%%%|-DWITH_XVIDEO|g ; \
		 s|%%%OSDEF%%%|-D_BSD|g ; \
		 s|%%%sound%%%|-DSOUND|g ; \
		 s|%%%joyconf%%%|conf|g' < Makefile.templ > Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cingb ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cingb_conf ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FAQ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

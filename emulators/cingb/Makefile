# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cingb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.32
CATEGORIES=	emulators

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Yet another Nintendo Game Boy emulator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2 xorg
USE_XORG=	x11 xext xv
USE_GITHUB=	yes
GH_ACCOUNT=	nakal

MAKE_ENV=	X11BASE="${LOCALBASE}"
ALL_TARGET=	standard

LDFLAGS+=	-lpthread

PLIST_FILES=	bin/cingb \
		bin/cingb_conf \
		man/man6/cingb.6.gz
PORTDOCS=	README.FAQ README.md

OPTIONS_DEFINE=	DEBUG DOCS
OPTIONS_SUB=	yes
DEBUG_ALL_TARGET+=	debug
DEBUG_PLIST_FILES=	bin/cingb_deb
DEBUG_PORTDOCS=	DEBUGGER

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "powerpc"
CPPFLAGS+=	-DUSE_LITTLE_ENDIAN
.endif

do-configure:
	@cd ${WRKSRC} && ${SED} -e \
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
	${INSTALL_PROGRAM} ${WRKSRC}/cingb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cingb_conf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/freebsd/cingb.6 ${STAGEDIR}${MANPREFIX}/man/man6/

do-install-DEBUG-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DEBUGGER ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cingb_deb ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FAQ ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

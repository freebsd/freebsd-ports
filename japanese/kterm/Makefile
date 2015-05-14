# $FreeBSD$

PORTNAME=	kterm
PORTVERSION=	6.2.0
PORTREVISION=	13
CATEGORIES=	japanese x11
MASTER_SITES=	PORTS_JP/kterm/:wp_jp \
		XCONTRIB/applications \
		LOCAL/shige/kterm/:wp_local \
		LOCAL/hrs/:pcemu
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		README.wallpaper.ja:wp_local,wp_jp \
		pcemu1.01alpha.tar.gz:pcemu
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/:nfs \
		http://www.asahi-net.or.jp/~hc3j-tkg/kterm/:wpi \
		http://dists.lovepeers.org/distfiles/:termios \
		LOCAL/shige/kterm/:color16 \
		LOCAL/nork/:termios \
		LOCAL/hrs/:utf
PATCHFILES=	${DISTNAME}.NFS-xauth.patch:nfs \
		${DISTNAME}-wpi.patch.gz:wpi \
		${DISTNAME}-color16.patch.gz:color16 \
		${DISTNAME}-termios-0.2.patch.gz:termios \
		${DISTNAME}.ext06.patch.gz:utf
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Xterm variant with Japanese support

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

USES=		imake
VGAFONT_USES=	fonts
USE_XORG=	xaw
CFLAGS+=	-Wno-return-type
PORTDOCS=	README.kt README.wallpaper.ja dot.termcap

OPTIONS_DEFINE=	TEKTRONIXEMU VGAFONT
OPTIONS_DEFAULT=	DEFAULT
OPTIONS_SINGLE=	SCROLLBAR
OPTIONS_SINGLE_SCROLLBAR=	DEFAULT XAW3DLIB NEXTAWLIB
OPTIONS_SUB=	yes

XAW3DLIB_DESC=	with Xaw3d scrollbar
LIB_DEPENDS_XAW3DLIB=	libXaw3d.so:${PORTSDIR}/x11-toolkits/Xaw3d
EXTRA_PATCHES_XAW3DLIB=	${PATCHDIR}/extra-patch-Xaw3d

NEXTAWLIB_DESC=	with neXtaw scrollbar
LIB_DEPENDS_NEXTAWLIB=	libneXtaw.so:${PORTSDIR}/x11-toolkits/neXtaw
EXTRA_PATCHES_NEXTAWLIB=${PATCHDIR}/extra-patch-neXtaw

TEKTRONIXEMU_DESC=	Tektronix emulation
EXTRA_PATCHES_TEKTRONIXEMU=${PATCHDIR}/extra-patch-Tektronix

VGAFONT_DESC=	install VGA font
BUILD_DEPENDS_VGAFONT= \
    ${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
    ${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
    ${LOCALBASE}/bin/bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

NKFCMD=		${LOCALBASE}/bin/nkf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVGAFONT}
post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	    ${DISTDIR}/${DIST_SUBDIR}/pcemu1.01alpha.tar.gz \
	    ${EXTRACT_AFTER_ARGS} -C ${WRKDIR} pcemu1.01alpha/vga.bdf
	cd ${WRKDIR}/pcemu1.01alpha && \
	    ${LOCALBASE}/bin/bdftopcf vga.bdf | ${GZIP_CMD} > vga.pcf.gz
post-install-vgafont:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/pcemu1.01alpha/vga.pcf.gz \
	    ${STAGEDIR}${FONTSDIR}
post-install: post-install-vgafont
.endif

post-build:
	${NKFCMD} -e -u ${WRKSRC}/kterm.jman \
	    | ${GZIP_CMD} > ${WRKSRC}/kterm.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/kterm.1.gz ${STAGEDIR}${MANPREFIX}/man/ja/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
	    ${WRKSRC}/README.kt \
	    ${DISTDIR}/${DIST_SUBDIR}/README.wallpaper.ja \
	    ${FILESDIR}/dot.termcap \
	    ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	kterm
PORTVERSION=	6.2.0
PORTREVISION=	13
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_PORTS_JP:S/$/:wp_jp/} \
		${MASTER_SITE_XCONTRIB} \
		${MASTER_SITE_LOCAL:S/$/:wp_local,pcemu/}
MASTER_SITE_SUBDIR= applications \
		kterm/:wp_jp \
		shige/kterm/:wp_local \
		hrs/:pcemu
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		README.wallpaper.ja:wp_local,wp_jp \
		pcemu1.01alpha.tar.gz:pcemu
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/:nfs \
		http://www.asahi-net.or.jp/~hc3j-tkg/kterm/:wpi \
		http://dists.lovepeers.org/distfiles/:termios \
		${MASTER_SITE_LOCAL:S/$/:color16,termios,utf/}
PATCH_SITE_SUBDIR=	shige/kterm/:color16 \
			nork/:termios \
			hrs/:utf
PATCHFILES=	${DISTNAME}.NFS-xauth.patch:nfs \
		${DISTNAME}-wpi.patch.gz:wpi \
		${DISTNAME}-color16.patch.gz:color16 \
		${DISTNAME}-termios-0.2.patch.gz:termios \
		${DISTNAME}.ext06.patch.gz:utf
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	An xterm variant with Japanese support

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

USE_IMAKE=	yes
USE_XORG=	xaw

MAN1=		kterm.1
MANLANG=	"" ja

.if !defined(NOPORTDOCS)
PORTDOCS=	README.kt README.wallpaper.ja dot.termcap
.endif

OPTIONS_DEFINE=	TEKTRONIXEMU VGAFONT
OPTIONS_DEFAULT=	DEFAULT
OPTIONS_SINGLE=	SCROLLBAR
OPTIONS_SINGLE_SCROLLBAR=	DEFAULT XAW3DLIB NEXTAWLIB

XAW3DLIB_DESC= with Xaw3d scrollbar
NEXTAWLIB_DESC= with neXtaw scrollbar
TEKTRONIXEMU_DESC= Tektronix emulation
VGAFONT_DESC= install VGA font

NKFCMD=		${LOCALBASE}/bin/nkf

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MXAW3DLIB}
LIB_DEPENDS+=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Xaw3d
.endif
.if ${PORT_OPTIONS:MNEXTAWLIB}
LIB_DEPENDS+=	neXtaw:${PORTSDIR}/x11-toolkits/neXtaw
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-neXtaw
.endif

.if ${PORT_OPTIONS:MTEKTRONIXEMU}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Tektronix
.endif

.if ${PORT_OPTIONS:MVGAFONT}
PLIST_SUB=	VGAFONT=""
post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/pcemu1.01alpha.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR} pcemu1.01alpha/vga.bdf
	cd ${WRKDIR}/pcemu1.01alpha && \
		${LOCALBASE}/bin/bdftopcf vga.bdf | ${GZIP_CMD} > vga.pcf.gz
post-install-vgafont:
	${MKDIR} ${PREFIX}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKDIR}/pcemu1.01alpha/vga.pcf.gz \
		${PREFIX}/lib/X11/fonts/misc
	${LOCALBASE}/bin/mkfontdir ${PREFIX}/lib/X11/fonts/misc
post-install: post-install-vgafont
.else
PLIST_SUB=	VGAFONT="@comment "
.endif

post-build:
	${NKFCMD} -e -u ${WRKSRC}/kterm.jman \
		| ${GZIP_CMD} > ${WRKSRC}/${MAN1}.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1}.gz ${MANPREFIX}/man/ja/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/README.kt \
		${DISTDIR}/${DIST_SUBDIR}/README.wallpaper.ja \
		${FILESDIR}/dot.termcap \
		${DOCSDIR}/README.wallpaper.ja \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>

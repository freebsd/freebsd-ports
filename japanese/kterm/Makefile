# New ports collection makefile for:	kterm
# Date created:				18 November 1994
# Whom:					asami
#
# $FreeBSD$
#

PORTNAME=	kterm
PORTVERSION=	6.2.0
PORTREVISION=	11
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
		${MASTER_SITE_LOCAL:S/$/:jisx0213,color16,termios/}
PATCH_SITE_SUBDIR=	shige/kterm/:jisx0213,color16 \
			nork/:termios
PATCHFILES=	${DISTNAME}.NFS-xauth.patch:nfs \
		${DISTNAME}-wpi.patch.gz:wpi \
		${DISTNAME}-jisx0213.patch.gz:jisx0213 \
		${DISTNAME}-color16.patch.gz:color16 \
		${DISTNAME}-termios-0.2.patch.gz:termios
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xterm variant with Japanese support

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

USE_IMAKE=	yes
USE_XORG=	xaw

MAN1=		kterm.1
MANLANG=	"" ja

.if !defined(NOPORTDOCS)
PORTDOCS=	README.kt README.wallpaper.ja dot.termcap
.endif

OPTIONS=	XAW3DLIB "with Xaw3d scrollbar" off \
		NEXTAWLIB "with neXtaw scrollbar" off \
		TEKTRONIXEMU "Tektronix emulation" off \
		VGAFONT "install VGA font" off

NKFCMD=		${LOCALBASE}/bin/nkf

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XAW3DLIB)
LIB_DEPENDS+=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Xaw3d
.elif !defined(WITHOUT_NEXTAWLIB)
LIB_DEPENDS+=	neXtaw.6:${PORTSDIR}/x11-toolkits/neXtaw
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-neXtaw
.endif

.if !defined(WITHOUT_TEKTRONIXEMU)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Tektronix
.endif

.if !defined(WITHOUT_VGAFONT)
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/README.kt \
		${DISTDIR}/${DIST_SUBDIR}/README.wallpaper.ja \
		${FILESDIR}/dot.termcap \
		${DOCSDIR}/README.wallpaper.ja \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>

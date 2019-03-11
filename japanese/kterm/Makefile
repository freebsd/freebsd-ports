# $FreeBSD$

PORTNAME=	kterm
PORTVERSION=	6.2.0
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	.fb6
PORTREVISION=	15
CATEGORIES=	japanese x11
MASTER_SITES=	LOCAL/hrs:pcemu
DISTFILES=	pcemu1.01alpha.tar.gz:pcemu
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Xterm variant with Japanese support

LICENSE=	MIT

BUILD_DEPENDS=	nkf:japanese/nkf

BROKEN_aarch64=	Fails to build: fatal error: kfontlist.c file not found

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd
VGAFONT_USES=	fonts
CFLAGS+=	-Wno-return-type
PORTDOCS=	README.kt README.wallpaper.ja dot.termcap

OPTIONS_DEFINE=	TEKTRONIXEMU VGAFONT DOCS
OPTIONS_DEFAULT=DEFAULT
OPTIONS_SINGLE=	SCROLLBAR
OPTIONS_SINGLE_SCROLLBAR=	DEFAULT XAW3DLIB NEXTAWLIB
OPTIONS_SUB=	yes

XAW3DLIB_DESC=	with Xaw3d scrollbar
XAW3DLIB_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

NEXTAWLIB_DESC=	with neXtaw scrollbar
NEXTAWLIB_LIB_DEPENDS=	libneXtaw.so:x11-toolkits/neXtaw

TEKTRONIXEMU_DESC=	Tektronix emulation

VGAFONT_DESC=	install VGA font
VGAFONT_EXTRACT_DEPENDS= \
    ${LOCALBASE}/bin/bdftopcf:x11-fonts/bdftopcf
VGAFONT_BUILD_DEPENDS= \
    ${LOCALBASE}/bin/mkfontscale:x11-fonts/mkfontscale

NKFCMD=		${LOCALBASE}/bin/nkf

post-extract-VGAFONT-on:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	    ${DISTDIR}/${DIST_SUBDIR}/pcemu1.01alpha.tar.gz \
	    ${EXTRACT_AFTER_ARGS} -C ${WRKDIR} pcemu1.01alpha/vga.bdf
	cd ${WRKDIR}/pcemu1.01alpha && \
	    ${LOCALBASE}/bin/bdftopcf vga.bdf | ${GZIP_CMD} > vga.pcf.gz

post-extract-TEKTRONIXEMU-on:
	echo "#undef  KTERM_NOTEK" >> ${WRKSRC}/kterm.h
post-extract-TEKTRONIXEMU-off:
	echo "#undef  KTERM_NOTEK" >> ${WRKSRC}/kterm.h
	echo "#define KTERM_NOTEK" >> ${WRKSRC}/kterm.h

post-extract-XAW3DLIB-on:
	echo "#undef KTERM_XAW3D" >> ${WRKSRC}/kterm.h
	echo "#undef USE_XAW3DLIB" >> ${WRKSRC}/kterm.h
	echo "#define KTERM_XAW3D" >> ${WRKSRC}/kterm.h
	echo "#define USE_XAW3DLIB" >> ${WRKSRC}/kterm.h
post-extract-XAW3DLIB-off:
	echo "#undef  KTERM_XAW3D" >> ${WRKSRC}/kterm.h

post-extract-NEXTAWLIB-on:
	echo "#undef KTERM_XAW3D" >> ${WRKSRC}/kterm.h
	echo "#undef USE_NEXTAWLIB" >> ${WRKSRC}/kterm.h
	echo "#define KTERM_XAW3D" >> ${WRKSRC}/kterm.h
	echo "#define USE_NEXTAWLIB" >> ${WRKSRC}/kterm.h
post-extract-NEXTAWLIB-off:
	echo "#undef  KTERM_XAW3D" >> ${WRKSRC}/kterm.h

post-extract:
	${ECHO_CMD} "#undef InstallXtermSetUID" >> ${WRKSRC}/kterm.h
	${ECHO_CMD} "#define InstallXtermSetUID 0" >> ${WRKSRC}/kterm.h

post-build:
	${NKFCMD} -e -u ${WRKSRC}/kterm.jman \
	    | ${GZIP_CMD} > ${WRKSRC}/kterm.1.gz
post-install:
	${INSTALL_MAN} ${WRKSRC}/kterm.1.gz ${STAGEDIR}${MANPREFIX}/man/ja/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
	    ${WRKSRC}/README.kt \
	    ${WRKSRC}/README.wallpaper.ja \
	    ${FILESDIR}/dot.termcap \
	    ${STAGEDIR}${DOCSDIR}
post-install-VGAFONT-on:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/pcemu1.01alpha/vga.pcf.gz \
	    ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>

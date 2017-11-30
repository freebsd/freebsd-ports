# Created by: Gennady Sorokopud <gena@NetVision.net.il>
# $FreeBSD$

PORTNAME=	xmcd
PORTVERSION=	3.3.2
PORTREVISION=	19
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/3.3.2/src/

MAINTAINER=	deischen@FreeBSD.org
COMMENT=	Motif CD player

LIB_DEPENDS+=	libvorbis.so:audio/libvorbis \
		libFLAC.so:audio/flac
RUN_DEPENDS+=	lame:audio/lame

USES=		imake motif ncurses
USE_XORG=	x11 xext xaw xmu xp xpm xt sm ice
PLIST_SUB+=	RELEASE=${OSREL:R:R} ARCH=${ARCH} OPSYS=${OPSYS}
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

LIBBINDIR=	${STAGEDIR}${PREFIX}/lib/X11/xmcd/bin-${OPSYS}_${OSREL:R:R}-${ARCH}

BROKEN_aarch64=		Fails to compile: many undefined symbols in xorg.cf
BROKEN_armv6=		Fails to compile: many undefined symbols in xorg.cf
BROKEN_armv7=		Fails to install: strip: xmcd/bin-FreeBSD_12-armv7/cda failed: No such file or directory
BROKEN_mips64=		Fails to compile: many undefined symbols in xorg.cf
BROKEN_powerpc64=	Fails to compile: many undefined symbols in xorg.cf

pre-patch:
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${WRKSRC}/xmcd_d/XMcd.ad.in

post-patch:
	@${SED} -e "s;@PREFIX@;${STAGDIR}${PREFIX};g" ${WRKSRC}/xmcd_d/XMcd.ad.in \
		> ${WRKSRC}/xmcd_d/XMcd.ad

post-configure:
	@${REINPLACE_CMD} \
		-e 's: BINDIR .*:BINDIR=${STAGEDIR}${PREFIX}/bin:' \
		-e 's: LIBDIR .*:LIBDIR=${STAGEDIR}${PREFIX}/lib/X11:' \
		-e 's: MANDIR .*:MANDIR=${STAGEDIR}${PREFIX}/man/man1:' \
		-e 's: MANSUFFIX .*:MANSUFFIX=1:' \
		-e 's/^Makefile::/^Makefile:/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's/^XBINPERM=4711/XBINPERM=711/' \
		-e "s/^(id \| fgrep 'uid=0(root)')/true/" >/dev/null 2>&1 \
		${WRKSRC}/install.sh

post-install:
	${STRIP_CMD} ${LIBBINDIR}/cda ${LIBBINDIR}/gobrowser \
		${LIBBINDIR}/has_alsa ${LIBBINDIR}/xmcd
	${INSTALL_DATA} ${WRKSRC}/xmcd_d/XMcd.ad \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XMcd
	${RM} ${STAGEDIR}${PREFIX}/bin/xmcd
	${RM} ${STAGEDIR}${PREFIX}/bin/cda
	${LN} -sf .xmcd_start ${STAGEDIR}${PREFIX}/bin/xmcd
	${LN} -sf .xmcd_start ${STAGEDIR}${PREFIX}/bin/cda
	${REINPLACE_CMD} \
		-e 's:^BINDIR=.*:XMCDLIB=${PREFIX}/bin:' \
		-e 's:^XMCDLIB=.*:XMCDLIB=${PREFIX}/lib/X11/xmcd:' \
		-e 's:^DISCOGDIR=.*:DISCOGDIR=${PREFIX}/lib/X11/xmcd/discog:' \
		-e 's:XMCD_LIBDIR=.*:XMCD_LIBDIR=${PREFIX}/lib/X11/xmcd:' \
		${STAGEDIR}${PREFIX}/lib/X11/xmcd/scripts/genidx \
		${STAGEDIR}${PREFIX}/bin/.xmcd_start
	${REINPLACE_CMD} \
		-e 's:${STAGEDIR}::' \
		${STAGEDIR}${PREFIX}/lib/X11/xmcd/discog/discog.html \
		${STAGEDIR}${PREFIX}/lib/X11/xmcd/config/config.sh \
		${STAGEDIR}${PREFIX}/lib/X11/xmcd/bin-${OPSYS}_${OSREL:R:R}-${ARCH}/README
	${FIND} ${STAGEDIR}${PREFIX} -name \*.bak -delete
	${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>

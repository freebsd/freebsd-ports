# New ports collection makefile for:	vice
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	1.16
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/ \
		http://distfiles.opendarwin.org/
PKGNAMESUFFIX?=	${GNOME_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore's C64, C128, VIC20, PET, and CBM-II

.if !defined(VICE_WITH_GNOME)
LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

RESTRICTED=	ROMs are copyrighted by Commodore Business Machines

USE_XPM=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	MAKEINFOFLAGS="--no-split"

.if defined(VICE_WITH_GNOME)
GNOME_SUFFIX=	-gnome
USE_GNOME=	gnomelibs
CONFIGURE_ARGS=	--enable-gnomeui
CONFLICTS?=	vice-1.*
.else
CONFIGURE_ARGS=	--with-xaw3d
CONFLICTS?=	vice-gnome-1.*
.endif

INFO=		vice
MAN1=		vice.1 c1541.1 petcat.1
MLINKS=		vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xplus4.1 \
		vice.1 xcbm2.1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
BUILD_DEPENDS+=	bdftopcf:${X_CLIENTS_PORT}
.endif

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
# ../src/resid/libresid.a(wave.o)(.rodata+0x0): relocation truncated to fit: GPREL32 *UND*
BROKEN=		"GPREL relocation truncated"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/vice.info*

post-patch:
	@${MV} ${WRKSRC}/man/vice.1 ${WRKSRC}/man/vice.1.sed
	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		${WRKSRC}/man/vice.1.sed > ${WRKSRC}/man/vice.1

pre-install:
	${MKDIR} ${DOCSDIR} ${PREFIX}/lib/vice/fonts
	${INSTALL_DATA} ${WRKSRC}/data/fonts/vice-cbm.bdf \
		${PREFIX}/lib/vice/fonts/

post-install:
	@${LN} -sf vice_toc.html ${DOCSDIR}/index.html

.include <bsd.port.post.mk>

# New ports collection makefile for:	vice
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	1.14
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/
.if defined(VICE_WITH_GNOME)
PKGNAMESUFFIX=	-gnome
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore's C64, C128, VIC20, PET, and CBM-II

.if !defined(VICE_WITH_GNOME)
LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

RESTRICTED=	ROMs are copyrighted by Commodore Business Machines

USE_XPM=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	MAKEINFOFLAGS="--no-split"
USE_GCC=	3.2

.if defined(VICE_WITH_GNOME)
USE_GNOME=	gnomelibs
CONFIGURE_ARGS=	--enable-gnomeui
.else
CONFIGURE_ARGS=	--with-xaw3d
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

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
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

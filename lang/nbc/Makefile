# New ports collection makefile for:	nbcx
# Date created:				4 April 2007
# Whom:					Ivan "Rambius" Ivanov <rambiusparkisanius@gmail.com>
#					Jason Bacon <jwbacon@tds.net>
# $FreeBSD$
#

PORTNAME=		nbc
PORTVERSION=		1.0.1.b32
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bricxcc
DISTNAME=		${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=		.tgz

MAINTAINER=		rambiusparkisanius@gmail.com
COMMENT=		NBC is a programming language for the LEGO MINDSTORMS NXT product

BUILD_DEPENDS=		fpc:${PORTSDIR}/lang/fpc \
			${UNITSDIR}/fcl-base/Package.fpc:${PORTSDIR}/devel/fpc-fcl-base
RUN_DEPENDS=		legoctl:${PORTSDIR}/devel/legoctl

USE_GMAKE=		yes
USE_DOS2UNIX=		yes

MAKEFILE=		nbcfreebsd.mak
SUB_FILES=		pkg-message
WRKSRC=			${WRKDIR}/nxt

BUILDNAME=		${ARCH}-freebsd
FPC_MINVER=		2.2.0
UNITSDIR=		${LOCALBASE}/lib/fpc/${FPC_MINVER}/units/${BUILDNAME}

PLIST_FILES=		bin/nbc \
			share/nbc/history.txt \
			share/nbc/readme.txt \
			include/nbc/NXCDefs.h \
			include/nbc/NBCCommon.h \
			include/nbc/NXTDefs.h
PLIST_DIRS=		share/nbc \
			include/nbc

post-depends:
.if exists(${LOCALBASE}/bin/fpc)
FPC_VER!=	${LOCALBASE}/bin/fpc -iV
FPC_REQVER!=	${ECHO_CMD} $$(expr ${FPC_VER:C/^[^\.]*\.//} \>= ${FPC_MINVER:C/^[^\.]*\.//})

.if (${FPC_REQVER} != 1)
IGNORE=	requires fpc ${FPC_MINVER} or above. Please upgrade
.endif
.endif

do-install:
	${MKDIR} ${PREFIX}/include/nbc ${PREFIX}/share/nbc
	${INSTALL_PROGRAM} ${WRKSRC}/nbc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/nbc
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/nbc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

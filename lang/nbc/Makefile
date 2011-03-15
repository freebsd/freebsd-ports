# New ports collection makefile for:	nbcx
# Date created:				4 April 2007
# Whom:					Ivan "Rambius" Ivanov <rambiusparkisanius@gmail.com>
#					Jason Bacon <jwbacon@tds.net>
# $FreeBSD$
#

PORTNAME=		nbc
PORTVERSION=		1.2.1.r4
CATEGORIES=		lang
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	bricxcc/NBC_NXC/NBC%20release%20${PORTVERSION:S/.r/%20r/}
DISTNAME=		${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=		.tgz

MAINTAINER=		rene@FreeBSD.org
COMMENT=		NBC is a programming language for the LEGO MINDSTORMS NXT product

MAKE_JOBS_UNSAFE=	yes
MAKEFILE=		nbcunix.mak

OPTIONS=	ROBOCTL	"Include roboctl to communicate with the NXT"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ROBOCTL)
RUN_DEPENDS=		legoctl:${PORTSDIR}/devel/roboctl
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS=		usb:${PORTSDIR}/devel/libusb
.endif

USE_GMAKE=		yes
USE_DOS2UNIX=		yes
USE_FPC=		fcl-base fcl-image

SUB_FILES=		pkg-message
WRKSRC=			${WRKDIR}/NXT

PLIST_FILES=		bin/nbc \
			include/nbc/NXCDefs.h \
			include/nbc/NBCCommon.h \
			include/nbc/NXTDefs.h
PLIST_DIRS=		include/nbc

.if !defined(NOPORTDOCS)
PORTDOCS=		Changelog \
			Readme
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/${MAKEFILE}

do-install:
	${MKDIR} ${PREFIX}/include/nbc
	${INSTALL_PROGRAM} ${WRKSRC}/nbc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/nbc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/Changelog ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/Readme ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

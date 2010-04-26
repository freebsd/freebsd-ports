# New ports collection makefile for:	nbcx
# Date created:				4 April 2007
# Whom:					Ivan "Rambius" Ivanov <rambiusparkisanius@gmail.com>
#					Jason Bacon <jwbacon@tds.net>
# $FreeBSD$
#

PORTNAME=		nbc
PORTVERSION=		1.0.1.b36
CATEGORIES=		lang
MASTER_SITES=		http://bricxcc.sourceforge.net/nbc/beta/
DISTNAME=		${PORTNAME}-${PORTVERSION}.unix-src
EXTRACT_SUFX=		.tgz

MAINTAINER=		rambiusparkisanius@gmail.com
COMMENT=		NBC is a programming language for the LEGO MINDSTORMS NXT product

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

.if !defined(NO_INSTALL_MANPAGES)
MAN1=			nbc.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/include/nbc
	${INSTALL_PROGRAM} ${WRKSRC}/nbc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/nbc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/Changelog ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/Readme ${DOCSDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKDIR}/doc/nbc.1 ${MANPREFIX}/man/man1
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	nbcx
# Date created:				4 April 2007
# Whom:					Ivan "Rambius" Ivanov <rambiusparkisanius@gmail.com>
#					Jason Bacon <jwbacon@tds.net>
# $FreeBSD$
#

PORTNAME=		nbc
PORTVERSION=		1.0.1.b32
PORTREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		SF/bricxcc/NBC_NXC/NBC%20beta%2032
DISTNAME=		${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=		.tgz

MAINTAINER=		rambiusparkisanius@gmail.com
COMMENT=		NBC is a programming language for the LEGO MINDSTORMS NXT product

RUN_DEPENDS=		legoctl:${PORTSDIR}/devel/roboctl

USE_GMAKE=		yes
USE_DOS2UNIX=		yes
USE_FPC=		fcl-base

MAKEFILE=		nbcfreebsd.mak
SUB_FILES=		pkg-message
WRKSRC=			${WRKDIR}/nxt

PLIST_FILES=		bin/nbc \
			share/nbc/history.txt \
			share/nbc/readme.txt \
			include/nbc/NXCDefs.h \
			include/nbc/NBCCommon.h \
			include/nbc/NXTDefs.h
PLIST_DIRS=		share/nbc \
			include/nbc

do-install:
	${MKDIR} ${PREFIX}/include/nbc ${PREFIX}/share/nbc
	${INSTALL_PROGRAM} ${WRKSRC}/nbc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/nbc
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/nbc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

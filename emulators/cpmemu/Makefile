# New ports collection makefile for:	cpm-emulator
# Version required:	0.2.1
# Date created:		28 June 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

DISTNAME=	cpm-0.2.1
PKGNAME=	cpmemu-0.2.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.cdrom.com/pub/linux/slackware/source/extra-stuff/CPM-80-emulator/

MAINTAINER=	ports@FreeBSD.org

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpm ${PREFIX}/bin/cpmemu
	${INSTALL_PROGRAM} ${WRKSRC}/format ${PREFIX}/bin/cpmformat
	${MKDIR} ${PREFIX}/share/cpm
	${INSTALL_DATA} ${WRKSRC}/z80-binaries/cpm.sys ${PREFIX}/share/cpm
	${INSTALL_DATA} ${WRKSRC}/z80-binaries/cd.com ${PREFIX}/share/cpm
	${INSTALL_DATA} ${WRKSRC}/z80-binaries/link.com ${PREFIX}/share/cpm
	${INSTALL_DATA} ${WRKSRC}/z80-binaries/xccp.com ${PREFIX}/share/cpm

.include <bsd.port.mk>

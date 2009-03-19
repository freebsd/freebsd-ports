# New ports collection makefile for:    Star Trek Voyager: Elite Forces Server
# Whom:					nik@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	stvef-server
PORTVERSION=	1.20
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	ftp://ftp.multiplay.co.uk/pub/games/fps/eliteforce/patches/linux/
DISTFILES=	stvefLinuxDedicated120.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Star Trek Voyager: Elite Forces dedicated server for Linux

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
WRKSRC=		${WRKDIR}/Linux

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

GAMEDIR=	${PREFIX}/games/stvef/

# files which should be installed with executables perms
EXECUTABLES=	linuxstvefded_1.2-static linuxstvefded_1.2-glibc2.1.3

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/linuxstvefded_1.2-static
	${BRANDELF} -t Linux ${WRKSRC}/linuxstvefded_1.2-glibc2.1.3

do-install:
	${MKDIR} ${GAMEDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/linuxstvefded_1.2-static ${GAMEDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/linuxstvefded_1.2-glibc2.1.3 ${GAMEDIR}
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${GAMEDIR}
	${MKDIR} ${GAMEDIR}/baseEF
	${INSTALL_DATA} ${WRKSRC}/baseEF/server.cfg ${GAMEDIR}/baseEF

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:    Star Trek Voyager: Elite Forces Server
# Whom:					nik@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	stvef-server
PORTVERSION=	1.20
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	ftp.multiplay.co.uk/pub/games/fps/eliteforce/patches/linux/ \
		ftp://3dgamers.in-span.net/pub/3dgamers/games/stveliteforce/ 
DISTFILES=	stveflinuxdedicated120.zip

MAINTAINER=	nik@FreeBSD.org
COMMENT=	Star Trek Voyager: Elite Forces dedicated server for Linux

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
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

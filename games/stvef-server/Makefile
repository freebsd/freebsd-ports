# New ports collection makefile for:    Star Trek Voyager: Elite Forces Server
# Whom:					nik@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	stvef-server
PORTVERSION=	1.20
CATEGORIES=	games linux
MASTER_SITES=	ftp://3dgamers.in-span.net/pub/3dgamers/games/stveliteforce/
DISTFILES=	stveflinuxdedicated120.zip

MAINTAINER=	nik@FreeBSD.org

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
USE_LINUX_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Linux
STRIP=

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

GAMEDIR=	${PREFIX}/usr/games/stvef/

# files which should be installed with executables perms
EXECUTABLES=	linuxstvefded_1.2-static linuxstvefded_1.2-glibc2.1.3

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

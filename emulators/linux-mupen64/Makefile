# New ports collection makefile for:	linux-mupen64
# Date created:			04 Oct 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.3
CATEGORIES=	emulators linux
MASTER_SITES=	http://mupen64.emulation64.com/files/
PKGNAMEPREFIX=	linux-

MAINTAINER=	tlp@liquidx.org
COMMENT=	A Nintendo 64 emulator (Linux version)

RUN_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base-8 \
		${LINUXBASE}/usr/X11R6/lib/libXi.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri \
		${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

USE_BZIP2=	yes

ONLY_FOR_ARCHS=	i386
INSTALLS_SHLIB=	yes
NO_BUILD=	yes

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

do-install:
	${MKDIR} ${PREFIX}/lib/linux-mupen64
	${MKDIR} ${PREFIX}/lib/linux-mupen64/lang
	${MKDIR} ${PREFIX}/lib/linux-mupen64/save
	${MKDIR} ${PREFIX}/lib/linux-mupen64/plugins
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/mupen64.ini ${PREFIX}/lib/linux-mupen64/mupen64.ini
	${INSTALL_DATA} ${WRKSRC}/whatsnew.txt ${DOCSDIR}/whatsnew.txt
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lang/* ${PREFIX}/lib/linux-mupen64/lang
	${INSTALL_DATA} ${WRKSRC}/save/* ${PREFIX}/lib/linux-mupen64/save
	${INSTALL_DATA} ${WRKSRC}/plugins/* ${PREFIX}/lib/linux-mupen64/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mupen64 ${PREFIX}/lib/linux-mupen64/mupen64
	${INSTALL_SCRIPT} ${FILESDIR}/linux-mupen64 ${PREFIX}/bin/linux-mupen64
	${INSTALL_SCRIPT} ${FILESDIR}/linux-mupen64_install ${PREFIX}/bin/linux-mupen64_install

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:    games
# Version required:	1.8
# Date created:         Mon Dec  9 09:42:37 CST 1996
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

DISTNAME=	doom-1.8
PKGNAME=	linuxdoom-1.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/doom
DISTFILES=	linux-doom-1.8.tar.gz musserver.tgz smooth-joystick4doom.tgz

MAINTAINER=	erich@FreeBSD.org

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=    /compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
PKGINSTALL=	${WRKDIR}/INSTALL

post-patch:
	@(cd ${WRKSRC}/joystick4doom; make clean)
	@(cd ${WRKSRC}/musserver; make clean)

pre-install:
	@${SED} 's,@PREFIX@,${PREFIX},' ${PKGDIR}/INSTALL.in > ${PKGINSTALL}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

# New ports collection makefile for:    games
# Version required:	1.8
# Date created:         Mon Dec  9 09:42:37 CST 1996
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.6 1998/12/13 08:47:40 asami Exp $
#

DISTNAME=	doom-1.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/doom
DISTFILES=	linux-doom-1.8.tar.gz musserver.tgz smooth-joystick4doom.tgz

MAINTAINER=	erich@FreeBSD.org

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

BROKEN=		repository copy
USE_XLIB=	yes
NO_WRKSUBDIR=	yes
PKGINSTALL=	${WRKDIR}/INSTALL

post-patch:
	@(cd ${WRKSRC}/joystick4doom; make clean)
	@(cd ${WRKSRC}/musserver; make clean)

pre-install:
	@sed 's,@PREFIX@,${PREFIX},' ${PKGDIR}/INSTALL.in > ${PKGINSTALL}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

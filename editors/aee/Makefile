# New ports collection makefile for:	aee
# Version required:	2.2.1
# Date created:		19 Aug 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

DISTNAME=	aee-2.2.1
CATEGORIES=	editors
MASTER_SITES=	http://www.users.uswest.net/~hmahon/sources/ \
		http://awwm.linuxberg.com/files/console/network/ \
		http://powerlinux.linuxberg.com/files/console/network/

MAINTAINER=	kbyanc@posi.net

.if !defined(BUILD_XAE)
ALL_TARGET=	main
pre-fetch:
	@${ECHO}
	@${ECHO} "If you would like to also install the X11 version of aee (xae)"
	@${ECHO} "use 'make install BUILD_XAE=yes'. However, the X11 interface looks"
	@${ECHO} "almost exactly like the text-based curses version."
	@${ECHO}
.else
USE_XLIB=	yes
ALL_TARGET=	both
PLIST=		${PKGDIR}/PLIST.xae
.endif

MAN1=		aee.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aee ${PREFIX}/bin
	${LN} ${PREFIX}/bin/aee ${PREFIX}/bin/rae
	${INSTALL_MAN} ${WRKSRC}/aee.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/help.ae ${PREFIX}/lib
.if defined(BUILD_XAE)
	${INSTALL_PROGRAM} ${WRKSRC}/xae ${PREFIX}/bin
	${LN} ${PREFIX}/bin/xae ${PREFIX}/bin/rxae
.endif

.include <bsd.port.mk>

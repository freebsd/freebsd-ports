# New ports collection makefile for:	dtcyber
# Date created:		2006-09-03
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	dtcyber
PORTVERSION=	2.0b1
CATEGORIES=	emulators
MASTER_SITES=	http://members.iinet.net.au/~tom-hunter/
DISTNAME=	dtcyber20b1

MAINTAINER=	trasz@freebsd.org
COMMENT=	Desktop CYBER Emulator

USE_ZIP=	yes
USE_DOS2UNIX=	yes
NO_WRKSUBDIR=	yes
USE_XLIB=	yes
INSTALL_TARGET=
MAKEFILE=	Makefile.x11
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	bin/dtcyber %%EXAMPLESDIR%%/cyber.ini %%EXAMPLESDIR%%/cos.tap
PLIST_DIRS=	%%EXAMPLESDIR%%

pre-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.x11
	${REINPLACE_CMD} -e 's|CFLAGS  = -O2|CFLAGS+= |' ${WRKSRC}/Makefile.x11
	${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|' ${WRKSRC}/Makefile.x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dtcyber ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cyber.ini ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Os/cos.tap ${EXAMPLESDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

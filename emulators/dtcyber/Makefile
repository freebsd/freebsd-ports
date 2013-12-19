# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dtcyber
PORTVERSION=	2.0b1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://members.iinet.net.au/~tom-hunter/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trasz
DISTNAME=	dtcyber20b1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop CYBER Emulator

USES=		dos2unix
USE_ZIP=	yes
USE_XORG=	x11
NO_WRKSUBDIR=	yes
INSTALL_TARGET=
MAKEFILE=	Makefile.x11

SUB_FILES=	pkg-message
PLIST_FILES=	bin/dtcyber %%EXAMPLESDIR%%/cyber.ini %%EXAMPLESDIR%%/cos.tap
PLIST_DIRS=	%%EXAMPLESDIR%%

pre-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.x11
	${REINPLACE_CMD} -e 's|CFLAGS  = -O2|CFLAGS+= |' ${WRKSRC}/Makefile.x11
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' ${WRKSRC}/Makefile.x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dtcyber ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cyber.ini ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Os/cos.tap ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	pearpc
# Date created:				22 May 2004
# Whom:					Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	pearpc
PORTVERSION=	0.1.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	PowerPC emulator

USE_XLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-fpo
PKGMESSAGE=	${WRKDIR}/pkg-message

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/src/Makefile

post-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/video.x ${DATADIR}/video.x
	@${SED} -e 's,PREFIX,${PREFIX},g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${PREFIX}/etc/ppccfg.example

.include <bsd.port.mk>

# New ports collection makefile for: bzflag
# Date created:		2000/08/12
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	bzflag
PORTVERSION=	1.7e.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bzflag
DISTNAME=	${PORTNAME}-${PORTVERSION:S/e./e/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A multiplayer 3D tank battle game

USE_XLIB=	yes
USE_MESA=	yes
USE_REINPLACE=	yes

MAKE_ENV=	PORTCFLAGS="${CFLAGS}" PORTCXXFLAGS="${CXXFLAGS}" \
		PORTPREFIX="${PREFIX}" PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

MAN6=	bzflag.6 bzfrelay.6 bzfls.6 bzfs.6

do-configure:
	@${CP} ${FILESDIR}/config-sys ${WRKSRC}/
	${REINPLACE_CMD} "s,libusb.h,libusbhid.h,g" \
		${WRKSRC}/src/platform/XWindow.h
	${REINPLACE_CMD} "s,malloc.h,stdlib.h,g" \
		${WRKSRC}/src/bzflag/HUDRenderer.cxx

post-build:
	@(cd ${WRKSRC}/man && ${MAKE} targets)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	@${INSTALL_MAN}	${WRKSRC}/man/*.6 ${PREFIX}/man/man6/
	@${MKDIR} ${PREFIX}/share/bzflag/data
	@${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/share/bzflag/data/

.include <bsd.port.mk>

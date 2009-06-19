# New ports collection makefile for:	libnxt
# Date created:		2007-05-05
# Whom:			Jason Bacon <bacon11@tds.net>
#
# $FreeBSD$
#

PORTNAME=	libnxt
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Lego NXT library

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons \
		python:${PORTSDIR}/lang/python

SUB_FILES=	pkg-message
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

do-build:
	(cd ${WRKSRC}; scons)

do-install:
	${MKDIR} ${PREFIX}/include/libnxt
	${INSTALL_PROGRAM} ${WRKSRC}/fwflash ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fwexec ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libnxt.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/libnxt
.for file in ${WRKSRC}/*.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/libnxt
.endfor

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>

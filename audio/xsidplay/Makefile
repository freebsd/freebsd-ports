# New ports collection makefile for:   xsidplay
# Date created:        28 November 1999
# Whom:                Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xsidplay
PORTVERSION=	1.6b11
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/ \
		http://www.freenix.no/~anders/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_QT2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	MOC="${X11BASE}/bin/moc2"
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-sidplay-inc=${LOCALBASE}/include \
		--with-sidplay-lib=${LOCALBASE}/lib \
		--with-x-includes=${X11BASE}/include \
		--with-x-libraries=${X11BASE}/lib

CFLAGS+=	${PTHREAD_CFLAGS}

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include <bsd.port.post.mk>

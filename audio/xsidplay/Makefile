# New ports collection makefile for:   xsidplay
# Date created:        28 November 1999
# Whom:                Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xsidplay
PORTVERSION=	1.6b12
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/ \
		http://www.freenix.no/~anders/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_QT_VER=	2
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=--with-sidplay-inc=${LOCALBASE}/include \
		--with-sidplay-lib=${LOCALBASE}/lib

CFLAGS+=	${PTHREAD_CFLAGS}

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include <bsd.port.post.mk>

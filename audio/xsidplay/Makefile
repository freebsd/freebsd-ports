# New ports collection makefile for:   xsidplay
# Date created:        28 November 1999
# Whom:                Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xsidplay
PORTVERSION=	1.3.8
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/ \
		http://www.freenix.no/~anders/
DISTNAME=	${PORTNAME}-1_3_8
EXTRACT_SUFX=   _tar.gz

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	sidplay:${PORTSDIR}/audio/sidplay

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_QT=		YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/sidplay" \
		LDFLAGS=-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PKGNAME}

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400000
BROKEN=	"Doesn't build with gcc >= 2.8.1"
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include <bsd.port.post.mk>

# New ports collection makefile for:   xsidplay
# Date created:        28 November 1999
# Whom:                Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xsidplay
PORTVERSION=	1.3.9
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/ \
		http://www.freenix.no/~anders/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/./_/g}.tgz

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay

GNU_CONFIGURE=	YES
USE_QT=		YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin

.include <bsd.port.mk>

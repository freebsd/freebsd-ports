# New ports collection makefile for:   sidplay
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	sidplay
PORTVERSION=	1.0.9
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
DISTNAME=	${PORTNAME}-base-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org
COMMENT=	A Commodore SID-chip emulator that plays SID music files

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay

CONFIGURE_ARGS=	--with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-base-${PORTVERSION}
GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${PREFIX}/bin/sidplay ${PREFIX}/bin/sid2wav ${PREFIX}/bin/sidcon

.include <bsd.port.mk>

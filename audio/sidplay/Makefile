# New ports collection makefile for:   sidplay
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	sidplay
PORTVERSION=	1.0.4
CATEGORIES=	audio emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will
DISTNAME=	${PORTNAME}-base-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay

CONFIGURE_ARGS=	--with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-base-${PORTVERSION}
USE_LIBTOOL=	yes
USE_GMAKE=	yes

post-install:
	strip ${PREFIX}/bin/sidplay ${PREFIX}/bin/sid2wav ${PREFIX}/bin/sidcon

.include <bsd.port.mk>

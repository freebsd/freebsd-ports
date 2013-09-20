# Created by: Stefan Zehl <sec@42.org>
# $FreeBSD$

PORTNAME=	sidplay
PORTVERSION=	1.0.9
CATEGORIES=	audio emulators
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-base-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commodore SID-chip emulator that plays SID music files

LIB_DEPENDS=	sidplay:${PORTSDIR}/audio/libsidplay

CONFIGURE_ARGS=	--with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-base-${PORTVERSION}
GNU_CONFIGURE=	yes
NO_STAGE=	yes

post-install:
	${STRIP_CMD} ${PREFIX}/bin/sidplay ${PREFIX}/bin/sid2wav \
		${PREFIX}/bin/sidcon

.include <bsd.port.mk>

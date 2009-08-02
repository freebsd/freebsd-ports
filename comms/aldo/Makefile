# New ports collection makefile for:	aldo
# Date created:		16 March 2004
# Whom:			lambert@lambertfam.org
#
# $FreeBSD$
#

PORTNAME=	aldo
PORTVERSION=	0.7.5
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lambert@lambertfam.org
COMMENT=	Morse code training program

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262 automake:110 libtool:22
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"
USE_GMAKE=	yes

PLIST_FILES=	bin/aldo
MAN1=	aldo.1

post-patch:
	@${REINPLACE_CMD} -e 's|1.10|1.10.1|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aldo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aldo.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>

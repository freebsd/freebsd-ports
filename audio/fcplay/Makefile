# New ports collection makefile for:	xmms-fc
# Date created:			17 September 2000
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	fcplay
PORTVERSION=	0.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/mod/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${LOCALBASE}/include/sidplay/compconf.h:${PORTSDIR}/audio/libsidplay

CXXFLAGS+=	-I${PREFIX}/include -DHAVE_FREEBSD -DHAVE_MACHINE_SOUNDCARD_H
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/fcplay-${PORTVERSION}

post-install:
	${INSTALL} -d -m 555 ${PREFIX}/share/doc/fcplay
	@${INSTALL_DATA} ${WRKSRC}/ABOUT ${PREFIX}/share/doc/fcplay/
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/fcplay/
	@${INSTALL_DATA} ${WRKSRC}/POINTER ${PREFIX}/share/doc/fcplay/

.include <bsd.port.mk>

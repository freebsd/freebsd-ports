# New ports collection makefile for:	xmms-fc
# Date created:			17 September 2000
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	fcplay
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/mod/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${LOCALBASE}/include/sidplay/compconf.h:${PORTSDIR}/audio/libsidplay

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CXXFLAGS+=	-I${LOCALBASE}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/fcplay
	${INSTALL_DATA} ${WRKSRC}/ABOUT ${PREFIX}/share/doc/fcplay
	${INSTALL_DATA} ${WRKSRC}/POINTER ${PREFIX}/share/doc/fcplay
.endif

.include <bsd.port.mk>

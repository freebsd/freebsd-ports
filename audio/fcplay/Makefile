# New ports collection makefile for:	xmms-fc
# Date created:			17 September 2000
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	fcplay
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Future Composer Reference Player

BUILD_DEPENDS=	${LOCALBASE}/include/sidplay/compconf.h:${PORTSDIR}/audio/libsidplay

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CXXFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile (bad C++ code)"
.endif

post-patch:
.for f in configure Config.h.in
	@${REINPLACE_CMD} -e "s@machine/soundcard\.h@sys/soundcard\.h@g; \
		s@HAVE_MACHINE_SOUNDCARD_H@HAVE_SYS_SOUNDCARD_H@g" \
		${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/fcplay
	${INSTALL_DATA} ${WRKSRC}/ABOUT ${PREFIX}/share/doc/fcplay
	${INSTALL_DATA} ${WRKSRC}/POINTER ${PREFIX}/share/doc/fcplay
.endif

.include <bsd.port.post.mk>

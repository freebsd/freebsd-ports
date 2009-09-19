# New ports collection makefile for:    maplay
# Date created:         Feb 13 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	maplay
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tnt.uni-hannover.de/pub/MPEG/audio/other-servers/Maplay-Mirror/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	MPEG audio player/decoder decoding layer I and II MPEG audio streams

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/maplay
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's,machine/soundcard.h,sys/soundcard.h,' \
		${WRKSRC}/configuration.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/maplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>

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

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	MPEG audio player/decoder decoding layer I and II MPEG audio streams

NO_WRKSUBDIR=	yes

post-patch:
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/configuration.sh > ${WRKSRC}/configuration.sh.new
	@${MV} ${WRKSRC}/configuration.sh.new ${WRKSRC}/configuration.sh
	@${CHMOD} a+x ${WRKSRC}/configuration.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/maplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/maplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/maplay
.endif

.include <bsd.port.mk>

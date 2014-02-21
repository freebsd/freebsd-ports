# Created by: jkh
# $FreeBSD$

PORTNAME=	maplay
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tnt.uni-hannover.de/pub/MPEG/audio/other-servers/Maplay-Mirror/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	MPEG audio player/decoder decoding layer I and II MPEG audio streams

LICENSE=	GPLv2

USE_GCC=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/maplay
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,machine/soundcard.h,sys/soundcard.h,' \
		${WRKSRC}/configuration.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/maplay ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

# Created by: Francisco Gomez <francisco@gomezmarin.com>
# $FreeBSD$

PORTNAME=	mp3riot
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.linuxsecure.de/f2html/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mp3riot creates mp3 playlists, HTML files, etc

RUN_DEPENDS=	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info

USES=		perl5
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	example.unix groupfile CHANGELOG MANUAL mp3table.sql README repl.dat TODO utf.dat
PLIST_FILES=	bin/mp3riot

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3riot ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for item in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${item} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

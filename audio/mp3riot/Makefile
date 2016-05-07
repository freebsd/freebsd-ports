# Created by: Francisco Gomez <francisco@gomezmarin.com>
# $FreeBSD$

PORTNAME=	mp3riot
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.linuxsecure.de/f2html/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mp3riot creates mp3 playlists, HTML files, etc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-MP3-Info>=0:audio/p5-MP3-Info

USES=		perl5 shebangfix zip
SHEBANG_FILES=	mp3riot
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

PORTDOCS=	example.unix groupfile CHANGELOG MANUAL mp3table.sql README repl.dat TODO utf.dat
PLIST_FILES=	bin/mp3riot

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3riot ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for item in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${item} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

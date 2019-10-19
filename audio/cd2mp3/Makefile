# Created by: Jamie Heckford <jamie@blackhole.net>
# $FreeBSD$

PORTNAME=	cd2mp3
PORTVERSION=	0.82
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://mark.foster.cc/pub/freebsd/ports/distfiles/ \
		https://BSDforge.com/projects/source/audio/cd2mp3/ \
		LOCAL/feld

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Easy to use CD Ripping and MP3 Encoding tool

RUN_DEPENDS=	lame:audio/lame \
		dagrab:audio/dagrab

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	cd2mp3
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/cd2mp3

PLIST_FILES=	bin/cd2mp3
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cd2mp3 ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

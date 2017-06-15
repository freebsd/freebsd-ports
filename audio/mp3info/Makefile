# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	mp3info
PORTVERSION=	0.8.5a
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/mp3-utils/mp3info

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MP3 technical info viewer and ID3 1.x tag editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	GTK2 DOCS
GTK2_DESC=	Enable to have the gmp3info

PORTSCOUT=	skipv:0.8.5

ALL_TARGET=	mp3info
USES=		ncurses tar:tgz

PLIST_FILES=	bin/mp3info man/man1/mp3info.1.gz
PORTDOCS=	ChangeLog README mp3info.txt

GTK2_ALL_TARGET=	gmp3info
GTK2_PLIST_FILES=	bin/gmp3info
GTK2_USE=		GNOME=gtk20
GTK2_USES=		pkgconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3info ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/mp3info.1 ${STAGEDIR}${PREFIX}/man/man1/

do-install-GTK2-on:
	${INSTALL_PROGRAM} ${WRKSRC}/gmp3info ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	mp3info
PORTVERSION=	0.8.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mp3-utils/mp3info
DISTNAME=	${PORTNAME}-${PORTVERSION}a
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Tool to manipulate ID3 tags for MP3 files

LICENSE=	GPLv2

WANT_GNOME=	yes

PORTDOCS=	ChangeLog README mp3info.txt

OPTIONS_DEFINE=	GTK2
GTK2_DESC=	Enable to have the gmp3info

GTK2_USES=		pkgconfig
GTK2_USE=		GNOME=gtk20
GTK2_ALL_TARGET=	gmp3info
GTK2_PLIST_FILES=	bin/gmp3info

PLIST_FILES=	bin/mp3info man/man1/mp3info.1.gz

ALL_TARGET=	doc mp3info

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3info ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mp3info.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MGTK2}
	${INSTALL_PROGRAM} ${WRKSRC}/gmp3info ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	mp3info
# Date created:				19 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

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

PLIST_FILES=	bin/mp3info \
		%%WITH_GTK%%bin/gmp3info

MAN1=		mp3info.1

ALL_TARGET=	doc mp3info

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
PKGNAMESUFFIX=	-gtk
USE_GNOME+=	gtk20
ALL_TARGET+=	gmp3info
MAKE_ARGS=	install-gmp3info
PLIST_SUB+=	WITH_GTK=""
.else
PLIST_SUB+=	WITH_GTK="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3info ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mp3info.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

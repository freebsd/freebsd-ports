# New ports collection makefile for:	mp3info
# Date created:				19 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mp3info
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/mp3-utils/mp3info
EXTRACT_SUFX=	.tgz

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Tool to manipulate ID3 tags for MP3 files

WANT_GNOME=	yes

MAN1=		mp3info.1

.include <bsd.port.pre.mk>

ALL_TARGET=	doc mp3info

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
ALL_TARGET+=	gmp3info
PLIST_SUB+=	WITH_GTK=""
PKGNAMESUFFIX=	-gtk
.else
PLIST_SUB+=	WITH_GTK="@comment "
.endif

MAKE_ENV+=	GTK_CONFIG="${GTK_CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3info ${PREFIX}/bin
.if defined(HAVE_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/gmp3info ${PREFIX}/bin
.endif
	${INSTALL_MAN} ${WRKSRC}/mp3info.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/mp3info.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

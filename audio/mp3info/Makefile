# New ports collection makefile for:	mp3info
# Date created:				19 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		mp3info
PORTVERSION=		0.2.16
CATEGORIES=		audio
MASTER_SITES=		ftp://bimbo.hive.no/pub/mp3info/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=		ports@FreeBSD.org

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="${CFLAGS}"

MAN1=			mp3info.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mp3info ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/mp3info.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/mp3info
.for file in ChangeLog README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mp3info
.endfor
.endif

.include <bsd.port.mk>

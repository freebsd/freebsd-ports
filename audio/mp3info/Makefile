# New ports collection makefile for:	mp3info
# Date created:				19 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mp3info
PORTVERSION=	0.2.16
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://bimbo.hive.no/pub/mp3info/
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=		mp3info.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mp3info
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/mp3info
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mp3info
.endif

.include <bsd.port.mk>

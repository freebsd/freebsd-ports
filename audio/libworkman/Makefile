# New ports collection makefile for:	libworkman
# Date created:			8 August 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libworkman
PORTVERSION=	1.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim
DISTNAME=	${PORTNAME}-1999-06-20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Workman library required by some audio apps

WRKSRC=		${WRKDIR}/libworkman
USE_IMAKE=	yes
INSTALLS_SHLIB=	yes
CFLAGS+=	-fPIC

post-patch:
	@${CP} ${WRKSRC}/Config ${WRKSRC}/Config.orig;
	@${SED} -e 's^/usr/local/^${PREFIX}/^g' \
		${WRKSRC}/Config.orig > ${WRKSRC}/Config

.include <bsd.port.mk>

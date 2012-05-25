# Ports collection makefile for:	rftg
# Date created:			Apr 12, 2011
# Whom:				Miles V. Aronnax <miles@aronnax.net>
#
# $FreeBSD$
#

PORTNAME=	rftg
PORTVERSION=	0.8.1
CATEGORIES=	games
MASTER_SITES=	#

MAINTAINER=	miles@aronnax.net
COMMENT=	Race for the Galaxy AI, a computer version of the Rio Grande card game

RESTRICTED=	Contains licensed graphics that must be fetched manually

GNU_CONFIGURE=	yes
USE_GNOME=      gtk20
USE_BZIP2=      yes
DOWNLOAD_URL=   http://www.keldon.net/rftg/

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		"Race for the Galaxy AI contains images and card names that are copyright Rio Grande Games. They have granted Keldon Jones ( http://www.keldon.net ) permission to distribute them, but this does not appear to include redistribution rights. Please download ${DISTFILES} manually from ${DOWNLOAD_URL} and place it in ${DISTDIR}"
.endif

.include <bsd.port.post.mk>

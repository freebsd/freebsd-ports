# New ports collection makefile for:	nettoe
# Date created:		01 July 2001
# Whom:			Christopher Preston <rbg@gayteenresource.org>
#
# $FreeBSD$
#

PORTNAME=	nettoe
PORTVERSION=	1.0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nettoe

MAINTAINER=	rbg@gayteenresource.org

MAN6=		nettoe.6

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nettoe
.for I in AUTHORS BUGS COPYING ChangeLog INSTALL NEWS README TO-DO
	${INSTALL_DATA} ${WRKSRC}/$I ${PREFIX}/share/doc/nettoe
.endfor
.endif

.include <bsd.port.mk>

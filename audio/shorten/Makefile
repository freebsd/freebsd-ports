# New ports collection makefile for:   shorten
# Date created:        17 Feb 1999
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	shorten
PORTVERSION=	2.3a
CATEGORIES=	audio archivers
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/coding/
DISTNAME=	${PORTNAME}

MAINTAINER=	sec@42.org

RESTRICTED=	"May not be sold. May not be distributed if modified."
WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=		shorten.1

post-install:
	strip ${PREFIX}/bin/shorten

.include <bsd.port.mk>

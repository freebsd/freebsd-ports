# New ports collection makefile for:   shorten
# Date created:        17 Feb 1999
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	shorten
PORTVERSION=	3.1
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/software/

MAINTAINER=	sec@42.org

RESTRICTED=	"May not be sold."

MAN1=		shorten.1

post-install:
	strip ${PREFIX}/bin/shorten

.include <bsd.port.mk>

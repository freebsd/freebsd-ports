# New ports collection makefile for:   shorten
# Date created:        17 Feb 1999
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	shorten
PORTVERSION=	2.3a
CATEGORIES=	audio archivers
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner
DISTFILES=	${PORTNAME}.tar.gz

MAINTAINER=	sec@42.org

RESTRICTED=	"May not be sold. May not be distributed if modified."

MAN1=		shorten.1

post-install:
	strip ${PREFIX}/bin/shorten

.include <bsd.port.mk>

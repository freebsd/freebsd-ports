# New ports collection makefile for:   autobook
# Date created:        13 December 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	autobook
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	http://sources.redhat.com/autobook/

MAINTAINER=	edwin@mavetju.org
COMMENT=	GNU autoconf, automake and libtool - The Book

NO_BUILD=	yes	# it's only text!

do-install:
	${MKDIR} ${PREFIX}/share/doc/autobook
	${CP} ${WRKSRC}/* ${PREFIX}/share/doc/autobook

.include <bsd.port.mk>

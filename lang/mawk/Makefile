# ex:ts=8
# Ports collection makefile for:  mawk
# Date created:			  24 Dec 1998
# Whom:				  Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	mawk
PORTVERSION=	1.3.3
CATEGORIES=	lang
MASTER_SITES=	http://dl.droso.net/ports/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	erwin@lansing.dk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
ALL_TARGET=

MAN1=		mawk.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mawk ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/mawk.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

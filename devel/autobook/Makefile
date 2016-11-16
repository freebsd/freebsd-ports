# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	autobook
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://sources.redhat.com/autobook/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU autoconf, automake, and libtool - The Book

NO_BUILD=	yes	# it's only text!

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/autobook
	${CP} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/doc/autobook

.include <bsd.port.mk>

# New ports collection makefile for: fly
# Date created:         30 December 1997
# Whom:                 Juergen Unger <j.unger@choin.net>
#
# $FreeBSD$
#

PORTNAME=	fly
PORTVERSION=	1.6.5
CATEGORIES=	graphics
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	j.unger@choin.net
COMMENT=	Simple drawing language to generate GIFs on the fly

#this doesn't matter.. the program builds its own libgd.a.
#BUILD_DEPENDS=	${PREFIX}/lib/libgd\.a #can't use ports' gd..

MAKE_ENV=	PREFIX="${PREFIX}"
PLIST_FILES=	bin/fly

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin

.include <bsd.port.mk>

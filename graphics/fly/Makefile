# New ports collection makefile for: fly
# Version required:     1.6.4
# Date created:         30 December 1997
# Whom:                 Juergen Unger <j.unger@choin.net>
#
# $Id$
#

DISTNAME=       fly-1.6.4
CATEGORIES=	graphics
MASTER_SITES=   ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/ \
		ftp://ftp.ibrado.com/pub/fly/

MAINTAINER=     j.unger@choin.net

BUILD_DEPENDS=	${PREFIX}/lib/libgd\.a:${PORTSDIR}/graphics/gd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin

.include <bsd.port.mk>

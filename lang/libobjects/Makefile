# New ports collection makefile for:   libobjects
# Version required:    0.1.19
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id$
#

DISTNAME=	libobjects-0.1.19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	Nakai@technologist.com

GNU_CONFIGURE=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

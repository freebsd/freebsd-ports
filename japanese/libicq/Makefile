# New ports collection makefile for:   libicq
# Version required:		0.20
# Date Created:			22 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id$
#

DISTNAME=	libicq-0.20
PKGNAME=	ja-libicq-0.20
CATEGORIES=	japanese devel
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

PATCH_SITES=	http://flos.kuee.kyoto-u.ac.jp/soft/
PATCHFILES=	libicq-0.20ja.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

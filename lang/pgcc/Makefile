# New ports collection makefile for:	pgcc-current  - Pentium gcc
# Version required:	gcc-2.7.2 + Pentium patches current developement
# Date created:		Mi 18 Dez 1996 00:26:20 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=	gcc-2.7.2
PKGNAME=	pgcc-2.7.2-current
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

# note this is an http site 
PATCH_SITES=    http://www.nightflight.com/~pcg/data/
PATCHFILES=	gcc-2.7.2-961122.diff.gz

MAINTAINER=	andreas@klemm.gtn.com

WRKSRC=		${WRKDIR}/${DISTNAME}
PATCH_DIST_STRIP=	-p1 -N -E
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-gnu-as --with-gnu-ld pentium-freebsd
MAN1=		gcc.1 g++.1 cccp.1

do-build:
	cd ${WRKSRC} && ${MAKE} bootstrap

do-install:
	cd ${WRKSRC} && ${MAKE} install CC="stage2/xgcc -Bstage2/" CFLAGS="-pipe -O2"

.include <bsd.port.mk>

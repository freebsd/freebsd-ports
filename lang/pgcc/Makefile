# New ports collection makefile for:	pgcc-current  - Pentium gcc
# Version required:	gcc-2.7.2 + Pentium patches current developement
# Date created:		Mi 18 Dez 1996 00:26:20 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.7 1997/10/04 14:53:09 andreas Exp $
#

DISTNAME=	gcc-2.7.2
PKGNAME=	pgcc-2.7.2c
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cygnus.com/pub/egcs/snapshots/1997-09-24/ \
		ftp://ftp.ninemoons.com/pub/egcs/snapshots/1997-09-24/ \
		ftp://gd.tuwien.ac.at/gnu/egcs/snapshots/1997-09-24/ \
		ftp://ftp.ilog.fr/pub/Mirrors/egcs/snapshots/1997-09-24/ \
		ftp://ftp.goof.com/pub/pcg/egcs/snapshots/1997-09-24/ \
		http://www.goof.com/pcg/data/egcs/snapshots/1997-09-24/
DISTFILES=	egcs-970924.tar.gz

MAINTAINER=	andreas@FreeBSD.ORG

PATCH_SITES=	http://www.goof.com/pcg/data/source/ \
                ftp://ftp.maisel.int-evry.fr/pub/linux/pentium/source/

PATCHFILES=	egcs-970924-pgcc-970924.diff.gz \
		pgcc-970924-971008.diff.gz

FETCH_DEPENDS=	${PREFIX}/bin/autoconf:${PORTSDIR}/devel/autoconf

WRKSRC=		${WRKDIR}/egcs-970924
PATCH=		patch -p1
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-gnu-as --with-gnu-ld \
		pentium-freebsd

MAN1=		gcc.1 g++.1 cccp.1

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC} && ./configure
	cd ${WRKSRC} && ${MAKE} maintainer-clean

do-build:
	cd ${WRKSRC} && ${MAKE} bootstrap

do-install:
	cd ${WRKSRC} \
	&& ${MAKE} install CC="stage2/xgcc -Bstage2/" CFLAGS="-pipe -O2"

post-install:
	${MV} ${PREFIX}/bin/c++ ${PREFIX}/bin/pc++
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/pg++
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/pgcc

.include <bsd.port.mk>

# New ports collection makefile for:	pgcc-current  - Pentium gcc
# Version required:	gcc-2.7.2 + Pentium patches current developement
# Date created:		Mi 18 Dez 1996 00:26:20 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1997/07/20 16:03:14 andreas Exp $
#

DISTNAME=	gcc-2.7.2
PKGNAME=	pgcc-2.7.2c
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=    ftp://ftp.goof.com/pub/pcg/source/ \
                ftp://ftp.maisel.int-evry.fr/pub/linux/pentium/source/ \
                ftp://ftp.pmi.saitama-med.ac.jp/pub/pcg/

PATCHFILES=	gcc-2.7.2-970628.diff.gz \
		pgcc-970628-970706.diff.gz \
		pgcc-970706-970713.diff.gz \
		pgcc-970713-970721.diff.gz

MAINTAINER=	andreas@FreeBSD.ORG

FETCH_DEPENDS=	${PREFIX}/bin/autoconf:${PORTSDIR}/devel/autoconf

PATCH_DIST_STRIP=	-p1 -N -E
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

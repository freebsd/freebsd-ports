# New ports collection makefile for:	pgcc-current  - Pentium gcc
# Version required:	gcc-2.7.2 + Pentium patches current developement
# Date created:		Mi 18 Dez 1996 00:26:20 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.2 1996/12/24 05:29:43 asami Exp $
#

DISTNAME=	gcc-2.7.2
PKGNAME=	pgcc-2.7.2c
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

# note this is an http site 
PATCH_SITES=	http://www.iti.cs.tu-bs.de/soft/www.goof.com/pcg/data/ \
		http://www.nightflight.com/~pcg/data/ \
		http://www.goof.com/pcg/data/ \
		http://www.pmi.saitama-med.ac.jp/pcg/data/ \
		http://linux.cis.nctu.edu.tw/pcg/data/

PATCHFILES=	gcc-2.7.2-970222.diff.gz \
		pgcc-970222-970308.diff.gz \
		pgcc-970308-970329.diff.gz \
		pgcc-970329-970404.diff.gz \
		pgcc-970404-970426.diff.gz \
		pgcc-970426-970502.diff.gz \
		pgcc-970502-970509.diff.gz
#		This one makes configure fail:
#		pgcc-970509-970522.diff.gz

MAINTAINER=	andreas@FreeBSD.ORG

PATCH_DIST_STRIP=	-p1 -N -E
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-gnu-as --with-gnu-ld \
		pentium-freebsd

MAN1=		gcc.1 g++.1 cccp.1

do-build:
	cd ${WRKSRC} && ${MAKE} bootstrap

do-install:
	cd ${WRKSRC} && ${MAKE} install CC="stage2/xgcc -Bstage2/" CFLAGS="-pipe -O2"

.include <bsd.port.mk>

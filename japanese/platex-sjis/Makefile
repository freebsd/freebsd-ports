# New ports collection makefile for:	platex2e-sjis
# Version required:		<1998/02/17>+0
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1998/02/22 21:55:27 max Exp $
#

DISTNAME=	pl19980217s
PKGNAME=	ja-platex2e-sjis-1998.02.17.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1998-02-17/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pl980227.patch.gz.txt pl980323.patch.gz.txt \
		pl980409.patch.gz.txt pl980413.patch.gz.txt

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-sjis \
		platex-common:${PORTSDIR}/japanese/platex-common \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-sjis \
		platex-common:${PORTSDIR}/japanese/platex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/19980217
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

do-patch:
.for f in 0227 0323 0413
	@/usr/bin/uudecode -p ${DISTDIR}/${DIST_SUBDIR}/pl98${f}.patch.gz.txt \
	  | ${GZCAT} | nkf -s | ${PATCH} ${PATCH_DIST_ARGS}
.endfor
	@/usr/bin/uudecode -p ${DISTDIR}/${DIST_SUBDIR}/pl980409.patch.gz.txt \
	  | ${GZCAT} | nkf -s | ${SED} 3,33d | ${PATCH} ${PATCH_DIST_ARGS}
	@${RM} -f ${WRKSRC}/*.orig

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	/bin/ln -fs ptex ${PREFIX}/bin/platex

.include <bsd.port.mk>

# New ports collection makefile for:	platex2e-euc
# Version required:		<1997/07/02>+2
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1997/10/05 21:36:10 max Exp $
#

DISTNAME=	pl970702e
PKGNAME=	ja-platex2e-euc-97.07.02.2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1997-07-02/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jclasses.dtx.gz plpatch.ltx

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-euc \
		platex-common:${PORTSDIR}/japanese/platex-common \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-euc \
		platex-common:${PORTSDIR}/japanese/platex-common

WRKSRC=		${WRKDIR}/970702
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

post-extract:
	@nkf -e ${DISTDIR}/${DIST_SUBDIR}/plpatch.ltx > ${WRKSRC}/plpatch.ltx
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/jclasses.dtx.gz \
	  | nkf -e > ${WRKSRC}/jclasses.dtx

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	/bin/ln -fs ptex ${PREFIX}/bin/platex

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*

.include <bsd.port.mk>

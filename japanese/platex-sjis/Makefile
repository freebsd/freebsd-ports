# New ports collection makefile for:	platex2e-sjis
# Version required:		<1997/07/02>+2
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1997/11/10 11:22:49 asami Exp $
#

DISTNAME=	pl970702s
PKGNAME=	ja-platex2e-sjis-97.07.02.2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1997-07-02/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jclasses.dtx.gz plpatch.ltx

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-sjis \
		platex-common:${PORTSDIR}/japanese/platex-common \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-sjis \
		platex-common:${PORTSDIR}/japanese/platex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
WRKSRC=		${WRKDIR}/970702
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

post-extract:
	@nkf -s ${DISTDIR}/${DIST_SUBDIR}/plpatch.ltx > ${WRKSRC}/plpatch.ltx
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/jclasses.dtx.gz \
	  | nkf -s > ${WRKSRC}/jclasses.dtx

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	/bin/ln -fs ptex ${PREFIX}/bin/platex

.include <bsd.port.mk>

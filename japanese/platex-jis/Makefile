# New ports collection makefile for:	platex2e-jis
# Version required:		<1997/07/02>+2
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1997/10/05 19:34:51 max Exp $
#

DISTNAME=	pl970702j
PKGNAME=	ja-platex2e-jis-97.07.02.2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1997-07-02/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jclasses.dtx.gz plpatch.ltx

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-jis \
		platex-common:${PORTSDIR}/japanese/platex-common

WRKSRC=		${WRKDIR}/970702
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/plpatch.ltx ${WRKSRC}
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/jclasses.dtx.gz > ${WRKSRC}/jclasses.dtx

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	/bin/ln -fs ptex ${PREFIX}/bin/platex

.include <bsd.port.mk>

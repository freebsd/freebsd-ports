# New ports collection makefile for:	platex2e-sjis
# Version required:		<1998/09/01>
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1998/06/27 09:24:28 asami Exp $
#

DISTNAME=	pl19980901s
PKGNAME=	ja-platex2e-sjis-1998.09.01
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1998-09-01/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		plpatch.ltx jclasses.dtx tascmac.sty

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-sjis \
		platex-common:${PORTSDIR}/japanese/platex-common \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-sjis \
		platex-common:${PORTSDIR}/japanese/platex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/19980901
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

post-extract:
.for f in plpatch.ltx jclasses.dtx tascmac.sty
	@nkf -s ${DISTDIR}/${DIST_SUBDIR}/$f > ${WRKSRC}/$f
.endfor

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	@${LN} -fs ptex ${PREFIX}/bin/platex

.include <bsd.port.mk>

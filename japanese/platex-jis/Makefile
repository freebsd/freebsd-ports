# New ports collection makefile for:	platex2e-jis
# Version required:		<1998/02/17>+0
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1997/11/22 01:38:52 asami Exp $
#

DISTNAME=	pl19980217j
PKGNAME=	ja-platex2e-jis-1998.02.17.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1998-02-17/

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-jis \
		platex-common:${PORTSDIR}/japanese/platex-common
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-jis \
		platex-common:${PORTSDIR}/japanese/platex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
WRKSRC=		${WRKDIR}/19980217
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	/bin/ln -fs ptex ${PREFIX}/bin/platex

.include <bsd.port.mk>

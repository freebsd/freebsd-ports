# New ports collection makefile for:	platex2e-jis
# Version required:		<1999/08/09>
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	pl19990809j
PKGNAME=	ja-platex2e-jis-1999.08.09
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1999-08-09/

MAINTAINER=	max@FreeBSD.org

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-jis \
		platex-common:${PORTSDIR}/japanese/platex-common
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-jis \
		platex-common:${PORTSDIR}/japanese/platex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
WRKSRC=		${WRKDIR}/19990809
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	@${LN} -fs ptex ${PREFIX}/bin/platex

.include <bsd.port.mk>

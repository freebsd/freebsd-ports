# New ports collection makefile for:	platex2e-sjis
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	platex2e
PORTVERSION=	1999.08.09
PKGNAMESUFFIX=	-sjis
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/${PORTVERSION:S/./-/g}/
DISTNAME=	pl${PORTVERSION:S/.//g}s

MAINTAINER=	max@FreeBSD.org

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex${PKGNAMESUFFIX} \
		platex-common:${PORTSDIR}/japanese/platex-common
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex${PKGNAMESUFFIX} \
		platex-common:${PORTSDIR}/japanese/platex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
WRKSRC=		${WRKDIR}/${PORTVERSION:S/.//g}
DIST_SUBDIR=	${PORTNAME}

TEXMF=		${PREFIX}/share/texmf

do-build:
	@(cd ${WRKSRC}; ptex -ini plcore.ins; ptex -ini platex.ltx)

do-install:
	${MKDIR} ${TEXMF}/tex/platex/base
	@${CP} ${WRKSRC}/* ${TEXMF}/tex/platex/base
	${MV} -f ${TEXMF}/tex/platex/base/platex.fmt ${TEXMF}/web2c
	@${LN} -fs ptex ${PREFIX}/bin/platex

.include <bsd.port.mk>

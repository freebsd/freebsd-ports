# New ports collection makefile for:	platex2e-common
# Version required:		<1998/09/01>
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.24 1998/06/10 07:48:03 asami Exp $
#

DISTNAME=	base-9806
PKGNAME=	ja-platex2e-common-1998.09.01
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/1998-09-01/ \
		ftp://ftp.ams.org/pub/tex/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ecfonts-1.0.tar.gz tfm.tar \
		amsfonts-sources.tar.Z

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common
RUN_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
WRKSRC=		${WRKDIR}/base
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ecfonts-1.0.tar.gz  \
		amsfonts-sources.tar.Z
DIST_SUBDIR=	platex2e

TEXMF=		${PREFIX}/share/texmf

post-extract:
	@tar -C ${WRKDIR} -xf ${DISTDIR}/${DIST_SUBDIR}/tfm.tar

do-build:
	@(cd ${WRKSRC}; tex -ini unpack.ins ; tex -ini latex.ltx)

do-install:
	@${RM} -rf ${TEXMF}/tex/latex/base
	@${MKDIR} ${TEXMF}/tex/latex/base
	${CP} ${WRKSRC}/* ${TEXMF}/tex/latex/base
	${MV} -f ${TEXMF}/tex/latex/base/latex.fmt ${TEXMF}/web2c
	${MKDIR} ${TEXMF}/fonts/tfm/public/ams
	${CP} ${WRKDIR}/tfm/* ${TEXMF}/fonts/tfm/public/ams
	${MKDIR} ${TEXMF}/fonts/source/public/ams
	${CP} -R ${WRKDIR}/amsfonts/sources/* ${TEXMF}/fonts/source/public/ams
	${MKDIR} ${TEXMF}/fonts/tfm/public/ec
	${CP} ${WRKDIR}/ec/tfm/* ${TEXMF}/fonts/tfm/public/ec
	${MKDIR} ${TEXMF}/fonts/source/public/ec
	${CP} ${WRKDIR}/ec/src/* ${TEXMF}/fonts/source/public/ec
	@${LN} -fs tex ${PREFIX}/bin/latex
	@${LN} -fs latex ${PREFIX}/bin/platex-common

.include <bsd.port.mk>

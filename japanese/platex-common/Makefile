# New ports collection makefile for:	platex2e-common
# Date created:			05 Oct 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	platex2e
PORTVERSION=	1999.08.09
PKGNAMESUFFIX=	-common
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/${PORTVERSION:S/./-/g}/ \
		ftp://ftp.ams.org/pub/tex/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS
DISTFILES=	base-9906.tar.gz \
		ecfonts-1.0.tar.gz \
		tfm.tar \
		amsfonts-sources.tar.Z

MAINTAINER=	max@FreeBSD.org

BUILD_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common
RUN_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
WRKSRC=		${WRKDIR}/base
EXTRACT_ONLY=	${DISTFILES:Ntfm.tar}
DIST_SUBDIR=	${PORTNAME}

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

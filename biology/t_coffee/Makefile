# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t_coffee
PORTVERSION=	9.03
DISTVERSIONSUFFIX=	.r1318
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	http://www.tcoffee.org/Packages/Stable/Version_${PORTVERSION}${DISTVERSIONSUFFIX}/
DISTNAME=	T-COFFEE_distribution_Version_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple DNA or protein sequence alignment package

LICENSE=	GPLv2

RUN_DEPENDS=	clustalw:biology/clustalw

OPTIONS_DEFINE=	EXAMPLES

BUILD_WRKSRC=	${WRKSRC}/t_coffee_source

USES=		fortran
CFLAGS+=	-Wno-return-type
MAKE_ENV=	FCC="${FC} ${FFLAGS}"
MAKEFILE=	makefile

PORTEXAMPLES=	*
PLIST_FILES=	bin/TMalign bin/t_coffee

do-install:
	(cd ${BUILD_WRKSRC} \
		&& ${INSTALL_PROGRAM} TMalign t_coffee ${STAGEDIR}${PREFIX}/bin)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

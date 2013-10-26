# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t_coffee
PORTVERSION=	9.03
DISTVERSIONSUFFIX=	.r1318
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.tcoffee.org/Packages/Stable/%SUBDIR%/
MASTER_SITE_SUBDIR=	Version_${PORTVERSION}${DISTVERSIONSUFFIX}
DISTNAME=	T-COFFEE_distribution_Version_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiple DNA or protein sequence alignment package

LICENSE=	GPLv2

RUN_DEPENDS=	clustalw:${PORTSDIR}/biology/clustalw

OPTIONS_DEFINE=	EXAMPLES

BUILD_WRKSRC=	${WRKSRC}/t_coffee_source

USE_FORTRAN=	yes
MAKE_ENV=	FCC="${FC} ${FFLAGS}"
MAKEFILE=	makefile

PORTEXAMPLES=	*
PLIST_FILES=	bin/TMalign bin/t_coffee

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	(cd ${BUILD_WRKSRC} \
		&& ${INSTALL_PROGRAM} TMalign t_coffee ${PREFIX}/bin)
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	namazu2
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	namazu
PORTVERSION=	2.0.10
CATEGORIES=	japanese databases www textproc
MASTER_SITES=	# empty
PKGNAMESUFFIX=	2
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	nmz.5:${PORTSDIR}/databases/namazu2
RUN_DEPENDS=	${PM_BASE}/${PERL_ARCH}/NKF.pm:${PORTSDIR}/japanese/p5-nkf \
		${PM_BASE}/${PERL_ARCH}/Text/${MODULE_NAME}.pm:${PORTSDIR}/japanese/p5-Text-${MODULE_NAME}

PM_BASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

.if defined(WITH_CHASEN)
MODULE_NAME=	ChaSen
.else
MODULE_NAME=	Kakasi
.endif

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>

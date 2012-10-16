# New ports collection makefile for:	namazu2
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	namazu
PORTVERSION=	${NAMAZU_PORTVERSION}
CATEGORIES=	japanese databases www textproc
MASTER_SITES=	# empty
PKGNAMESUFFIX=	2
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meta-port of Namazu and Japanese support modules

LIB_DEPENDS=	nmz.8:${PORTSDIR}/databases/namazu2
RUN_DEPENDS=	ja-p5-nkf>=0:${PORTSDIR}/japanese/p5-nkf

PLIST=		"@comment this plist is intentionally left empty"

.if defined(WITH_CHASEN)
RUN_DEPENDS+=	ja-p5-Text-ChaSen>=0:${PORTSDIR}/japanese/p5-Text-ChaSen
.elif defined(WITH_KAKASI)
RUN_DEPENDS+=	ja-p5-Text-Kakasi>=0:${PORTSDIR}/japanese/p5-Text-Kakasi
.else
RUN_DEPENDS+=	ja-p5-MeCab>=0:${PORTSDIR}/japanese/p5-MeCab
.endif

.include "${.CURDIR}/../../databases/namazu2/Makefile.common"

NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>

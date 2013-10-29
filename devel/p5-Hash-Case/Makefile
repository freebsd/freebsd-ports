# Created by: Gea-Suan Lin
# $FreeBSD$

PORTNAME=	Hash-Case
PORTVERSION=	1.020
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0*$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for hashes with key-casing requirements

BUILD_DEPENDS=	p5-Log-Report>=0.26:${PORTSDIR}/devel/p5-Log-Report
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Devel-CheckOS
PORTVERSION=	1.76
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Check currently running OS

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Compare>=1.2100:devel/p5-Data-Compare \
		p5-File-Find-Rule>=0.28:devel/p5-File-Find-Rule
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

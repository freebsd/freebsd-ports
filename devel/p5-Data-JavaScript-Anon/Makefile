# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	Data-JavaScript-Anon
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Dump big dumb Perl structs to anonymous JavaScript structs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Default>=1.51:${PORTSDIR}/devel/p5-Class-Default \
		p5-Params-Util>=0.01:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

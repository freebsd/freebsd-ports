# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	B-OPCheck
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PL_check hacks using Perl callbacks

RUN_DEPENDS=	p5-B-Utils>=0:${PORTSDIR}/devel/p5-B-Utils \
		p5-Scope-Guard>=0:${PORTSDIR}/devel/p5-Scope-Guard \
		p5-XSLoader>=0:${PORTSDIR}/devel/p5-XSLoader
BUILD_DEPENDS:=	p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

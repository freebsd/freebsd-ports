# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-Perl-V
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Structured data retrieval of perl -V output

BUILD_DEPENDS=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>

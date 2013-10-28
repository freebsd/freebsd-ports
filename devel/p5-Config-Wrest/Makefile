# Created by: John Alden + Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	Config-Wrest
PORTVERSION=	1.036
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for reading and writing configuration data

BUILD_DEPENDS=	p5-Log-Trace>0:${PORTSDIR}/devel/p5-Log-Trace \
		p5-Any-Template>0:${PORTSDIR}/www/p5-Any-Template \
		p5-File-Policy>0:${PORTSDIR}/devel/p5-File-Policy
RUN_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Assertions>0:${PORTSDIR}/devel/p5-Test-Assertions

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

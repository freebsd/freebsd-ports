# Created by: John Alden + Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	Config-Wrest
PORTVERSION=	1.036
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl module for reading and writing configuration data

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Any-Template>0:www/p5-Any-Template \
		p5-File-Policy>0:devel/p5-File-Policy \
		p5-Log-Trace>0:devel/p5-Log-Trace
RUN_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Assertions>0:devel/p5-Test-Assertions

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

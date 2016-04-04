# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	Cache-AgainstFile
PORTVERSION=	1.016
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Cache data structures parsed from files, watching for updates

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Log-Trace>=0:devel/p5-Log-Trace
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Assertions>=0:devel/p5-Test-Assertions

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

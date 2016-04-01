# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	Paranoid
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Paranoia support for safer programs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-BerkeleyDB>=0.32:databases/p5-BerkeleyDB \
		p5-Unix-Syslog>=1.1:sysutils/p5-Unix-Syslog \
		p5-Socket6>=0.23:net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

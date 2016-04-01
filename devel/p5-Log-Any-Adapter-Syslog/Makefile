# Created by: Bill Brinzer <bill.brinzer@gmail.com>
# $FreeBSD$

PORTNAME=	Log-Any-Adapter-Syslog
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Send Log::Any logs to syslog

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Log-Any>=0:devel/p5-Log-Any \
		p5-Unix-Syslog>=0:sysutils/p5-Unix-Syslog
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockModule>=0:devel/p5-Test-MockModule \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

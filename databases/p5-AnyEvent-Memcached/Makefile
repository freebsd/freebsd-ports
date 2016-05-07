# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	AnyEvent-Memcached
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	AnyEvent memcached client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent-Connection>=0.05:devel/p5-AnyEvent-Connection \
		p5-AnyEvent>=5.0:devel/p5-AnyEvent \
		p5-String-CRC32>=0:devel/p5-String-CRC32 \
		p5-common-sense>=2:devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:devel/p5-Test-TCP \
		p5-lib-abs>=0.90:devel/p5-lib-abs
RUN_DEPENDS=	p5-AnyEvent-Connection>=0.05:devel/p5-AnyEvent-Connection \
		p5-AnyEvent>=5.0:devel/p5-AnyEvent \
		p5-String-CRC32>=0:devel/p5-String-CRC32 \
		p5-common-sense>=2:devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:devel/p5-Test-TCP \
		p5-lib-abs>=0.90:devel/p5-lib-abs

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	AnyEvent-Worker
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Manage blocking task in external process

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-common-sense>=2:devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:devel/p5-Test-TCP \
		p5-lib-abs>=0.90:devel/p5-lib-abs

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

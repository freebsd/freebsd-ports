# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	AnyEvent-Worker
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Manage blocking task in external process

BUILD_DEPENDS=	p5-AnyEvent>=5:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-common-sense>=2:${PORTSDIR}/devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:${PORTSDIR}/devel/p5-Test-TCP \
		p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		AnyEvent::Worker.3 AnyEvent::Worker::Pool.3

.include <bsd.port.mk>

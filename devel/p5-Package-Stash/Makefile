# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	Package-Stash
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Routines for manipulating stashes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	\
	p5-Dist-CheckConflicts>=0.02:${PORTSDIR}/devel/p5-Dist-CheckConflicts \
	p5-Module-Implementation>=0:${PORTSDIR}/devel/p5-Module-Implementation \
	p5-Package-DeprecationManager>=0:${PORTSDIR}/devel/p5-Package-DeprecationManager \
	p5-Package-Stash-XS>=0.22:${PORTSDIR}/devel/p5-Package-Stash-XS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=		Package::Stash.3 \
		Package::Stash::PP.3

.include <bsd.port.mk>

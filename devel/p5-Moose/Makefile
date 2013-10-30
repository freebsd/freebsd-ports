# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moose
PORTVERSION=	2.1005
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Complete modern object system for Perl 5

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Do not add devel/p5-Data-Visitor to TEST_DEPENDS to avoid cyclic dependency in tinderbox
BUILD_DEPENDS=	p5-Class-Load>=0.09:${PORTSDIR}/devel/p5-Class-Load \
		p5-Class-Load-XS>=0.01:${PORTSDIR}/devel/p5-Class-Load-XS \
		p5-Data-OptList>=0.107:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Devel-GlobalDestruction>=0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-Eval-Closure>=0.04:${PORTSDIR}/devel/p5-Eval-Closure \
		p5-List-MoreUtils>=0.28:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MRO-Compat>=0.05:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Package-DeprecationManager>=0.10:${PORTSDIR}/devel/p5-Package-DeprecationManager \
		p5-Package-Stash>=0.32:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Package-Stash-XS>=0.24:${PORTSDIR}/devel/p5-Package-Stash-XS \
		p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Exporter>=0.980:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Name>=0.05:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Try-Tiny>=0.02:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.007:${PORTSDIR}/devel/p5-CPAN-Meta-Check \
		p5-DateTime-Format-MySQL>=0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		p5-Declare-Constraints-Simple>=0:${PORTSDIR}/devel/p5-Declare-Constraints-Simple \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Module-Refresh>=0:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-SUPER>=0:${PORTSDIR}/devel/p5-SUPER \
		p5-Test-CheckDeps>=0.006:${PORTSDIR}/devel/p5-Test-CheckDeps \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0.001:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires

CFLAGS+=	-I.	# mop.h
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure extract

post-patch:
	@${REINPLACE_CMD} -e '/^check_conflicts()/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-Carp>=1.22:${PORTSDIR}/devel/p5-Carp
RUN_DEPENDS+=	p5-Carp>=1.22:${PORTSDIR}/devel/p5-Carp
.endif

.include <bsd.port.post.mk>

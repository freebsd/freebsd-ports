# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moose
PORTVERSION=	2.1605
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Complete modern object system for Perl 5

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Do not add p5-Data-Visitor to TEST_DEPENDS to avoid cyclic dependency
BUILD_DEPENDS=	p5-Class-Load>=0.09:${PORTSDIR}/devel/p5-Class-Load \
		p5-Class-Load-XS>=0.01:${PORTSDIR}/devel/p5-Class-Load-XS \
		p5-Data-OptList>=0.107:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Devel-GlobalDestruction>=0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-Devel-OverloadInfo>=0.004:${PORTSDIR}/devel/p5-Devel-OverloadInfo \
		p5-Devel-StackTrace>=1.33:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Eval-Closure>=0.04:${PORTSDIR}/devel/p5-Eval-Closure \
		p5-List-MoreUtils>=0.28:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MRO-Compat>=0.05:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Module-Runtime>=0.012:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Module-Runtime-Conflicts>=0.002:${PORTSDIR}/devel/p5-Module-Runtime-Conflicts \
		p5-Package-DeprecationManager>=0.10:${PORTSDIR}/devel/p5-Package-DeprecationManager \
		p5-Package-Stash>=0.32:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Package-Stash-XS>=0.24:${PORTSDIR}/devel/p5-Package-Stash-XS \
		p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Exporter>=0.980:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Identify>=0:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-Sub-Name>=0.05:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Try-Tiny>=0.17:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.011:${PORTSDIR}/devel/p5-CPAN-Meta-Check \
		p5-DBM-Deep>=0:${PORTSDIR}/databases/p5-DBM-Deep \
		p5-DateTime-Calendar-Mayan>=0:${PORTSDIR}/devel/p5-DateTime-Calendar-Mayan \
		p5-DateTime-Format-MySQL>=0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		p5-Declare-Constraints-Simple>=0:${PORTSDIR}/devel/p5-Declare-Constraints-Simple \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Locale-US>=0:${PORTSDIR}/misc/p5-Locale-US \
		p5-Module-Refresh>=0:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Params-Coerce>=0:${PORTSDIR}/devel/p5-Params-Coerce \
		p5-Specio>=0:${PORTSDIR}/devel/p5-Specio \
		p5-SUPER>=0:${PORTSDIR}/devel/p5-SUPER \
		p5-Test-CleanNamespaces>=0.13:${PORTSDIR}/devel/p5-Test-CleanNamespaces \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-DependentModules>=0:${PORTSDIR}/devel/p5-Test-DependentModules \
		p5-Test-LeakTrace>=0:${PORTSDIR}/devel/p5-Test-LeakTrace \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle \
		p5-Test-Fatal>=0.001:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Warnings>=0:${PORTSDIR}/devel/p5-Test-Warnings \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

CFLAGS+=	-I.	# mop.h
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure extract

post-patch:
	@${REINPLACE_CMD} -e '/^check_conflicts()/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.35:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.35:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Moose/Moose.so

.include <bsd.port.post.mk>

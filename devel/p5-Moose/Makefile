# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moose
PORTVERSION=	2.2013
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Complete modern object system for Perl 5

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

# Do not add p5-Data-Visitor to TEST_DEPENDS to avoid cyclic dependency
BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0.09:devel/p5-Class-Load \
		p5-Class-Load-XS>=0.01:devel/p5-Class-Load-XS \
		p5-Data-OptList>=0.107:devel/p5-Data-OptList \
		p5-Devel-GlobalDestruction>=0:devel/p5-Devel-GlobalDestruction \
		p5-Devel-OverloadInfo>=0.005:devel/p5-Devel-OverloadInfo \
		p5-Devel-StackTrace>=2.03:devel/p5-Devel-StackTrace \
		p5-Eval-Closure>=0.04:devel/p5-Eval-Closure \
		p5-MRO-Compat>=0.05:devel/p5-MRO-Compat \
		p5-Module-Runtime>=0.014:devel/p5-Module-Runtime \
		p5-Module-Runtime-Conflicts>=0.002:devel/p5-Module-Runtime-Conflicts \
		p5-Package-DeprecationManager>=0.11:devel/p5-Package-DeprecationManager \
		p5-Package-Stash>=0.32:devel/p5-Package-Stash \
		p5-Package-Stash-XS>=0.24:devel/p5-Package-Stash-XS \
		p5-Params-Util>=1.00:devel/p5-Params-Util \
		p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils \
		p5-Sub-Exporter>=0.980:devel/p5-Sub-Exporter \
		p5-Sub-Identify>=0:devel/p5-Sub-Identify \
		p5-Sub-Name>=0.20,1:devel/p5-Sub-Name \
		p5-Try-Tiny>=0.17:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.011:devel/p5-CPAN-Meta-Check \
		p5-DBM-Deep>=0:databases/p5-DBM-Deep \
		p5-DateTime-Calendar-Mayan>=0:devel/p5-DateTime-Calendar-Mayan \
		p5-DateTime-Format-MySQL>=0:devel/p5-DateTime-Format-MySQL \
		p5-Declare-Constraints-Simple>=0:devel/p5-Declare-Constraints-Simple \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Locale-US>=0:misc/p5-Locale-US \
		p5-Module-Refresh>=0:devel/p5-Module-Refresh \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Params-Coerce>=0:devel/p5-Params-Coerce \
		p5-Specio>=0:devel/p5-Specio \
		p5-SUPER>=0:devel/p5-SUPER \
		p5-Test-CleanNamespaces>=0.13:devel/p5-Test-CleanNamespaces \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-DependentModules>=0:devel/p5-Test-DependentModules \
		p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-Fatal>=0.001:devel/p5-Test-Fatal \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Requires>=0.05:devel/p5-Test-Requires \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-URI>=0:net/p5-URI

CFLAGS+=	-I.	# mop.h
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure extract

post-patch:
	@${REINPLACE_CMD} -e '/^check_conflicts()/d' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Moose/Moose.so

.include <bsd.port.mk>

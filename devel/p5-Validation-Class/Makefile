# $FreeBSD$

PORTNAME=	Validation-Class
PORTVERSION=	7.900022
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for centralized input validation for any application

RUN_DEPENDS=	\
	p5-Class-Forward>0:${PORTSDIR}/devel/p5-Class-Forward \
	p5-Hash-Flatten>0:${PORTSDIR}/devel/p5-Hash-Flatten \
	p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
	p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Module-Find>0:${PORTSDIR}/devel/p5-Module-Find \
	p5-Module-Runtime>0:${PORTSDIR}/devel/p5-Module-Runtime
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-Class-Method-Modifiers>0:${PORTSDIR}/devel/p5-Class-Method-Modifiers

PERL_CONFIGURE=	yes

MAN3=	\
	Validation::Class.3 \
	Validation::Class::Cookbook.3 \
	Validation::Class::Directive.3 \
	Validation::Class::Directive::Alias.3 \
	Validation::Class::Directive::Between.3 \
	Validation::Class::Directive::City.3 \
	Validation::Class::Directive::Creditcard.3 \
	Validation::Class::Directive::Date.3 \
	Validation::Class::Directive::Decimal.3 \
	Validation::Class::Directive::Default.3 \
	Validation::Class::Directive::DependsOn.3 \
	Validation::Class::Directive::Email.3 \
	Validation::Class::Directive::Error.3 \
	Validation::Class::Directive::Errors.3 \
	Validation::Class::Directive::Filtering.3 \
	Validation::Class::Directive::Filters.3 \
	Validation::Class::Directive::Help.3 \
	Validation::Class::Directive::Hostname.3 \
	Validation::Class::Directive::Label.3 \
	Validation::Class::Directive::Length.3 \
	Validation::Class::Directive::Matches.3 \
	Validation::Class::Directive::MaxAlpha.3 \
	Validation::Class::Directive::MaxDigits.3 \
	Validation::Class::Directive::MaxLength.3 \
	Validation::Class::Directive::MaxSum.3 \
	Validation::Class::Directive::MaxSymbols.3 \
	Validation::Class::Directive::Messages.3 \
	Validation::Class::Directive::MinAlpha.3 \
	Validation::Class::Directive::MinDigits.3 \
	Validation::Class::Directive::MinLength.3 \
	Validation::Class::Directive::MinSum.3 \
	Validation::Class::Directive::MinSymbols.3 \
	Validation::Class::Directive::Mixin.3 \
	Validation::Class::Directive::MixinField.3 \
	Validation::Class::Directive::Multiples.3 \
	Validation::Class::Directive::Name.3 \
	Validation::Class::Directive::Options.3 \
	Validation::Class::Directive::Pattern.3 \
	Validation::Class::Directive::Readonly.3 \
	Validation::Class::Directive::Required.3 \
	Validation::Class::Directive::SSN.3 \
	Validation::Class::Directive::State.3 \
	Validation::Class::Directive::Telephone.3 \
	Validation::Class::Directive::Time.3 \
	Validation::Class::Directive::Toggle.3 \
	Validation::Class::Directive::UUID.3 \
	Validation::Class::Directive::Validation.3 \
	Validation::Class::Directive::Value.3 \
	Validation::Class::Directive::Zipcode.3 \
	Validation::Class::Directives.3 \
	Validation::Class::Exporter.3 \
	Validation::Class::Listing.3 \
	Validation::Class::Mapping.3 \
	Validation::Class::Prototype.3 \
	Validation::Class::Simple.3 \
	Validation::Class::Simple::Streamer.3 \
	Validation::Class::Whitepaper.3

.include <bsd.port.mk>

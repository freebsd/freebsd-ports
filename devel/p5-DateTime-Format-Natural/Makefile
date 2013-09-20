# Created by: Timur I. Bakeyev <bat@cpan.org>
# $FreeBSD$

PORTNAME=	DateTime-Format-Natural
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Create machine readable date/time with natural parsing logic

BUILD_DEPENDS=	p5-boolean>=0:${PORTSDIR}/devel/p5-boolean \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Module-Util>=0:${PORTSDIR}/devel/p5-Module-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockTime>=0:${PORTSDIR}/devel/p5-Test-MockTime

USES=		perl5
USE_PERL5=	modbuild

MAN1=		dateparse.1

MAN3=		DateTime::Format::Natural.3 \
		DateTime::Format::Natural::Calc.3 \
		DateTime::Format::Natural::Compat.3 \
		DateTime::Format::Natural::Duration.3 \
		DateTime::Format::Natural::Expand.3 \
		DateTime::Format::Natural::Extract.3 \
		DateTime::Format::Natural::Formatted.3 \
		DateTime::Format::Natural::Helpers.3 \
		DateTime::Format::Natural::Lang::Base.3 \
		DateTime::Format::Natural::Lang::EN.3 \
		DateTime::Format::Natural::Rewrite.3 \
		DateTime::Format::Natural::Test.3 \
		DateTime::Format::Natural::Utils.3 \
		DateTime::Format::Natural::Wrappers.3

regression-test: build
	@cd ${WRKSRC} && ./Build test

NO_STAGE=	yes
.include <bsd.port.mk>

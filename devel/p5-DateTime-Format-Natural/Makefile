# New ports collection makefile for:	p5-DateTime-Format-Natural
# Date created:				22 Jul 2008
# Whom:					Timur I. Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Natural
PORTVERSION=	0.98
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Create machine readable date/time with natural parsing logic

BUILD_DEPENDS=	\
		p5-boolean>=0:${PORTSDIR}/devel/p5-boolean \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Module-Util>=0:${PORTSDIR}/devel/p5-Module-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockTime>=0:${PORTSDIR}/devel/p5-Test-MockTime

PERL_MODBUILD=	yes

MAN1=		dateparse.1

MAN3=		DateTime::Format::Natural.3 \
		DateTime::Format::Natural::Calc.3 \
		DateTime::Format::Natural::Compat.3 \
		DateTime::Format::Natural::Duration.3 \
		DateTime::Format::Natural::Extract.3 \
		DateTime::Format::Natural::Formatted.3 \
		DateTime::Format::Natural::Helpers.3 \
		DateTime::Format::Natural::Lang::Base.3 \
		DateTime::Format::Natural::Lang::EN.3 \
		DateTime::Format::Natural::Rewrite.3 \
		DateTime::Format::Natural::Test.3 \
		DateTime::Format::Natural::Utils.3 \
		DateTime::Format::Natural::Wrappers.3

.include <bsd.port.mk>

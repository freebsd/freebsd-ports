# Created by: Timur Bakeyev <bat@cpan.org>
# $FreeBSD$

PORTNAME=	Unicode-Stringprep
PORTVERSION=	1.104
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Preparation of Internationalized Strings (RFC 3454)

BUILD_DEPENDS=	p5-Unicode-Normalize>=1:${PORTSDIR}/textproc/p5-Unicode-Normalize
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

MAN3=		Unicode::Stringprep.3 \
		Unicode::Stringprep::BiDi.3 \
		Unicode::Stringprep::Mapping.3 \
		Unicode::Stringprep::Prohibited.3 \
		Unicode::Stringprep::Unassigned.3 \
		Unicode::Stringprep::_Common.3

.include <bsd.port.mk>

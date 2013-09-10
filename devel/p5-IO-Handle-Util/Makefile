# $FreeBSD$

PORTNAME=	IO-Handle-Util
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for working with IO::Handle like objects

RUN_DEPENDS=	\
	p5-IO-String>0:${PORTSDIR}/devel/p5-IO-String \
	p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter \
	p5-asa>0:${PORTSDIR}/devel/p5-asa
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

MAN3=	IO::Handle::Iterator.3 \
	IO::Handle::Prototype.3 \
	IO::Handle::Prototype::Fallback.3 \
	IO::Handle::Util.3

.include <bsd.port.mk>

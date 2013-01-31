# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mock-Quick
PORTVERSION=	1.105
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quickly mock objects and classes

RUN_DEPENDS=	p5-Exporter-Declare>=0:${PORTSDIR}/devel/p5-Exporter-Declare
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Fennec-Lite>=0:${PORTSDIR}/devel/p5-Fennec-Lite \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_MODBUILD=	yes

MAN3=		Mock::Quick.3 Object::Quick.3 \
		Mock::Quick::Class.3 \
		Mock::Quick::Method.3 \
		Mock::Quick::Object.3 \
		Mock::Quick::Object::Control.3 \
		Mock::Quick::Util.3

.include <bsd.port.mk>

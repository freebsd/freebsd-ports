# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Data-Throttler
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Limit data throughput

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Log4perl>=1:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Set-IntSpan>0:${PORTSDIR}/math/p5-Set-IntSpan \
		p5-Text-ASCIITable>0:${PORTSDIR}/textproc/p5-Text-ASCIITable \
		p5-YAML>=0.62:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Data::Throttler.3

.include <bsd.port.mk>

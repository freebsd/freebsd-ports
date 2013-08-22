# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	IO-Pipely
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Portably create pipe() or pipe-like handles, one way or another

BUILD_DEPENDS=	p5-Carp>=1.26:${PORTSDIR}/devel/p5-Carp \
		p5-Exporter>=5.68:${PORTSDIR}/devel/p5-Exporter \
		p5-base>=2.18:${PORTSDIR}/devel/p5-base \
		p5-Scalar-List-Utils>=1.29:${PORTSDIR}/lang/p5-Scalar-List-Utils

USES=		perl5
USE_PERL5=	configure

MAN3=		IO::Pipely.3

.include <bsd.port.mk>

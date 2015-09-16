# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	IO-Pipely
PORTVERSION=	0.005
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Portably create pipe() or pipe-like handles, one way or another

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Scalar-List-Utils>=1.29:${PORTSDIR}/lang/p5-Scalar-List-Utils

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-Exporter>=5.68:${PORTSDIR}/devel/p5-Exporter
RUN_DEPENDS+=	p5-Exporter>=5.68:${PORTSDIR}/devel/p5-Exporter
.endif

.include <bsd.port.post.mk>

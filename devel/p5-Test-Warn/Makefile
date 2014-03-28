# Created by: Brian Minard <bminard@flatfoot.ca>
# $FreeBSD$

PORTNAME=	Test-Warn
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to test methods for warnings

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp>=1.22:${PORTSDIR}/devel/p5-Carp \
		p5-Sub-Uplevel>=0.12:${PORTSDIR}/devel/p5-Sub-Uplevel
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

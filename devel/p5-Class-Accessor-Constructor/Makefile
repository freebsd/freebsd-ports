# $FreeBSD$

PORTNAME=	Class-Accessor-Constructor
PORTVERSION=	1.111590
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for constructor generator

RUN_DEPENDS=	\
	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-Class-Accessor-Complex>0:${PORTSDIR}/devel/p5-Class-Accessor-Complex \
	p5-Class-Accessor-Installer>=1.100880:${PORTSDIR}/devel/p5-Class-Accessor-Installer \
	p5-Data-Inherited>0:${PORTSDIR}/devel/p5-Data-Inherited
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::Accessor::Constructor.3 \
	Class::Accessor::Constructor::Base.3

.include <bsd.port.mk>

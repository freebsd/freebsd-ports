# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Classy
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:ISHIGAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to allow writing your unit tests in other modules than *.t

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Module-Find>=0.05:${PORTSDIR}/devel/p5-Module-Find \
		p5-Sub-Install>=0.920:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Term-Encoding>=0:${PORTSDIR}/devel/p5-Term-Encoding \
		p5-Test-UseAllModules>=0:${PORTSDIR}/devel/p5-Test-UseAllModules
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

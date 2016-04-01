# $FreeBSD$

PORTNAME=	signatures
PORTVERSION=	0.13
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subroutine signatures for Perl with no source filter

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0.08:devel/p5-B-Hooks-EndOfScope \
		p5-B-Hooks-OP-Check>=0.17:devel/p5-B-Hooks-OP-Check \
		p5-B-Hooks-OP-PPAddr>=0.03:devel/p5-B-Hooks-OP-PPAddr \
		p5-B-Hooks-Parser>=0.15:devel/p5-B-Hooks-Parser \
		p5-ExtUtils-Depends>=0.302:devel/p5-ExtUtils-Depends
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

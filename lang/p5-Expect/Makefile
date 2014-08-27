# $FreeBSD$

PORTNAME=	Expect
PORTVERSION=	1.30
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module inspired by the Tcl version of Expect

BUILD_DEPENDS=	p5-IO-Tty>=1.11:${PORTSDIR}/devel/p5-IO-Tty \
		p5-ExtUtils-MakeMaker>=6.64:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

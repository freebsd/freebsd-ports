# $FreeBSD$

PORTNAME=	Regexp-Assemble-Compressed
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to compress Regular Expression

RUN_DEPENDS=	\
	p5-Regexp-Assemble>0:${PORTSDIR}/devel/p5-Regexp-Assemble
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Regexp::Assemble::Compressed.3

.include <bsd.port.mk>

# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Astro-Hipparcos
PORTVERSION=	0.09
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for reading the Hipparcos star catalog

BUILD_DEPENDS=	p5-ExtUtils-XSpp>=0.06:${PORTSDIR}/devel/p5-ExtUtils-XSpp \
		p5-ExtUtils-ParseXS>=2.22:${PORTSDIR}/devel/p5-ExtUtils-ParseXS

MAKE_ARGS+=	"CC=g++"
USES=		perl5
USE_PERL5=	configure

MAN3=		Astro::Hipparcos::Record.3 \
		Astro::Hipparcos.3

.include <bsd.port.mk>

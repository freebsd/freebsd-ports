# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mo
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Micro Objects. Mo is less

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Class-XSAccessor>=0:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse

USE_PERL5=	configure
USES=		perl5

MAN3=		Mo.3 \
		Mo::Design.3 \
		Mo::Features.3 \
		Mo::Golf.3 \
		Mo::Hacking.3 \
		Mo::Inline.3 \
		Mo::Moose.3 \
		Mo::Mouse.3 \
		Mo::build.3 \
		Mo::builder.3 \
		Mo::chain.3 \
		Mo::coerce.3 \
		Mo::default.3 \
		Mo::exports.3 \
		Mo::import.3 \
		Mo::importer.3 \
		Mo::is.3 \
		Mo::option.3 \
		Mo::required.3 \
		Mo::xs.3

.include <bsd.port.mk>

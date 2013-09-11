# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Bidi
PORTVERSION=	2.01
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the libfribidi

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig
LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi

USE_PERL5=	configure
USES=		perl5

MAN1=		fribidi.pl.1
MAN3=		Text::Bidi.3 \
		Text::Bidi::Array.3 \
		Text::Bidi::Array::Byte.3 \
		Text::Bidi::Array::Long.3 \
		Text::Bidi::Paragraph.3

.include <bsd.port.mk>

# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Bidi
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the libfribidi

LIB_DEPENDS=	fribidi.3:${PORTSDIR}/converters/fribidi

USES=		perl5
USE_PERL5=	configure
CFLAGS+=	-I${LOCALBASE}/include
MAN3=	Text::Bidi.3 Text::Bidi::CapRTL.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Text-Bidi
# Date created:		2008-03-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Bidi
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the libfribidi

LIB_DEPENDS=	fribidi.3:${PORTSDIR}/converters/fribidi

PERL_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAN3=	Text::Bidi.3 Text::Bidi::CapRTL.3

.include <bsd.port.mk>

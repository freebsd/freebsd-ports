# New ports collection makefile for:	Net::LibLO
# Date created:		01 May 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-LibLO
PORTVERSION=	0.06
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for liblo Lightweight OSC library

LIB_DEPENDS=	lo:${PORTSDIR}/audio/liblo

PERL_CONFIGURE=	yes
USE_GNOME=	pkgconfig

MAN3=	\
	Net::LibLO.3 \
	Net::LibLO::Address.3 \
	Net::LibLO::Bundle.3 \
	Net::LibLO::Message.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Unix-Statgrab
# Date created:				June 20th, 2004
# Whom:					Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	Unix-Statgrab
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Perl extension for collecting information about the machine

LIB_DEPENDS=	statgrab.8:${PORTSDIR}/devel/libstatgrab

USE_GNOME=	pkgconfig

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	INC="`pkg-config libstatgrab --cflags`" \
			LIBS="`pkg-config libstatgrab --libs`"

MAN3=		Unix::Statgrab.3

.include <bsd.port.mk>

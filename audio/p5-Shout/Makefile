# New ports collection makefile for:	Shout
# Date created:				18 April 2001
# Whom:					leo
#
# $FreeBSD$
#

PORTNAME=	Shout
PORTVERSION=	0.99
CATEGORIES=	audio perl5
MASTER_SITES=	http://developer.icecast.org/libshout/releases/
PKGNAMEPREFIX=	p5-

MAINTAINER=	leo@florida.sarang.net

LIB_DEPENDS=	shout.1:${PORTSDIR}/audio/libshout

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Shout.3

pre-configure:
	@(cd ${WRKSRC} && ${RM} example.pl example2.pl)

.include <bsd.port.mk>

# New ports collection makefile for:	p5-JSON-XS-VersionOneAndTwo
# Date created:	   21 Nov 2008
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	JSON-XS-VersionOneAndTwo
PORTVERSION=	0.31
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Support versions 1 and 2 of JSON::XS

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/JSON/XS.pm:${PORTSDIR}/converters/p5-JSON-XS
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	JSON::XS::VersionOneAndTwo.3

.include <bsd.port.mk>

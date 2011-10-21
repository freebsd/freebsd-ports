# New ports collection makefile for:	Dancer-Session-Memcached
# Date created:		31 Dec 2010
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Session-Memcached
PORTVERSION=	0.2.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XSAWYERX
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	magik@roorback.net
COMMENT=	Memcached-based session backend for Dancer

BUILD_DEPENDS=	p5-Cache-Memcached>=0:${PORTSDIR}/databases/p5-Cache-Memcached \
		p5-Dancer>=0:${PORTSDIR}/www/p5-Dancer
RUN_DEPENDS=	p5-Cache-Memcached>=0:${PORTSDIR}/databases/p5-Cache-Memcached \
		p5-Dancer>=0:${PORTSDIR}/www/p5-Dancer

PERL_CONFIGURE=	yes

MAN3=		Dancer::Session::Memcached.3

.include <bsd.port.mk>

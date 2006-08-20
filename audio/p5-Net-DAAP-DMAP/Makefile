# New ports collection makefile for:	p5-Net-DAAP-DMAP
# Date created:		2004-08-08
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DAAP-DMAP
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl module for reading and writing DAAP structures

RUN_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::DAAP::DMAP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	devel/p5-autobox
# Date created:				25 July 2009
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	autobox
PORTVERSION=	2.55
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CH/CHOCOLATE/
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Call methods on native Perl types

BUILD_DEPENDS=	p5-Scope-Guard>=0.03:${PORTSDIR}/devel/p5-Scope-Guard
RUN_DEPENDS=	p5-Scope-Guard>=0.03:${PORTSDIR}/devel/p5-Scope-Guard

PERL_CONFIGURE=	5.8.1+

MAN3=	autobox.3

.include <bsd.port.mk>

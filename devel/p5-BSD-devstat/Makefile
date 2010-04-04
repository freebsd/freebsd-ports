# New ports collection makefile for:	BSD::devstat
# Date created:		25 Mar 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BSD-devstat
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of devstat(3) API

PERL_CONFIGURE=	yes

MAN3=	BSD::devstat.3

regression-test:
	cd ${WRKSRC} && make test

.include <bsd.port.mk>

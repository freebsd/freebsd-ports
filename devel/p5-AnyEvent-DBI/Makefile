# New ports collection makefile for:	p5-AnyEvent-DBI
# Date created:	   19 Mar 2010
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-DBI
PORTVERSION=	2.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	AnyEvent::DBI - asynchronous DBI access

RUN_DEPENDS=	p5-DBI>=1.0:${PORTSDIR}/databases/p5-DBI \
		p5-AnyEvent>=4.15:${PORTSDIR}/devel/p5-AnyEvent \
		p5-common-sense>=3.3:${PORTSDIR}/devel/p5-common-sense
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		AnyEvent::DBI.3

.include <bsd.port.mk>

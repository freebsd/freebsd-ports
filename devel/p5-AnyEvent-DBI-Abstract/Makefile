# New ports collection makefile for:	p5-AnyEvent-DBI-Abstract
# Date created:	   19 Mar 2010
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-DBI-Abstract
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	AnyEvent::DBI + SQL::Abstract

RUN_DEPENDS=	p5-AnyEvent-DBI>=0:${PORTSDIR}/devel/p5-AnyEvent-DBI \
		p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		AnyEvent::DBI::Abstract.3

.include <bsd.port.mk>

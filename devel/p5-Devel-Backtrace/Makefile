# New ports collection makefile for:  Devel-Backtrace
# Whom:		Andrey Kostenko <andrey@kostenko.name>
# Date created: 02 December 2009
#
# $FreeBSD$
#

PORTNAME=	Devel-Backtrace
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Object-oriented backtrace

BUILD_DEPENDS=	p5-String-Escape>=0:${PORTSDIR}/textproc/p5-String-Escape \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	p5-String-Escape>=0:${PORTSDIR}/textproc/p5-String-Escape \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor

PERL_CONFIGURE=	5.8+
MAN3=		Devel::Backtrace.3 \
		Devel::Backtrace::Point.3 \
		Devel::DollarAt.3

.include <bsd.port.mk>

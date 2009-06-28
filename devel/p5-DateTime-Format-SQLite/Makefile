# New ports collection makefile for:	p5-DateTime-Format-SQLite
# Date created:		23 june 2009
# Whom:			Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-SQLite
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Parse and format SQLite dates and times

BUILD_DEPENDS=	${SITE_PERL}/DateTime/Format/Builder.pm:${PORTSDIR}/devel/p5-DateTime-Format-Builder
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::SQLite.3

.include <bsd.port.mk>

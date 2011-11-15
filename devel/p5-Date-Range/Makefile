# New ports collection makefile for:	devel/p5-Date-Range
# Date created:				05 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Date-Range
PORTVERSION=	1.41
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Date::Range - work with a range of dates

BUILD_DEPENDS=	p5-Date-Simple>=0.03:${PORTSDIR}/devel/p5-Date-Simple
RUN_DEPENDS=	p5-Date-Simple>=0.03:${PORTSDIR}/devel/p5-Date-Simple

PERL_CONFIGURE=	yes

MAN3=		Date::Range.3

.include <bsd.port.mk>

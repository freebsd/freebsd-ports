# New ports collection makefile for:	devel/p5-Date-Range
# Date created:				05 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Date-Range
PORTVERSION=	1.40
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Date::Range - work with a range of dates

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Simple.pm:${PORTSDIR}/devel/p5-Date-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Date::Range.3

.include <bsd.port.mk>

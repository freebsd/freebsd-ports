# New ports collection makefile for:	p5-DateTime-Calendar-Hebrew
# Date created:	   3 octobre 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-Hebrew
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Dates in the Hebrew calendar

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Event/Sunrise.pm:${PORTSDIR}/devel/p5-DateTime-Event-Sunrise
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Calendar::Hebrew.3

.include <bsd.port.mk>

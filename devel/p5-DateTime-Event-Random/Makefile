# New ports collection makefile for:	p5-DateTime-Event-Random
# Date created:	   8 Jan 2004
# Whom:		   Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-Random
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DateTime extension for creating random datetimes

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::Random.3

.include <bsd.port.mk>

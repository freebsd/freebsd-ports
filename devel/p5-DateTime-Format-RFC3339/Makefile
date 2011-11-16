# Ports collection makefile for:	p5-DateTime-Format-RFC3339
# Date created:	   Fri Aug 21, 2009
# Whom:		   Dan Rench <citric@cubicone.tmetic.com>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-RFC3339
PORTVERSION=	1.0.5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	Parse and format RFC3339 times

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::RFC3339.3

.include <bsd.port.mk>

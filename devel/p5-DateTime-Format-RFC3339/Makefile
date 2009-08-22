# Ports collection makefile for:	p5-DateTime-Format-RFC3339
# Date created:	   Fri Aug 21, 2009
# Whom:		   Dan Rench <citric@cubicone.tmetic.com>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-RFC3339
PORTVERSION=	v1.0.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	Parse and format RFC3339 times

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS=	${RUN_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME:S/00//}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::RFC3339.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-DateTime-Format-Pg
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Pg
PORTVERSION=	0.16.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.(...)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format PostgreSQL dates and times

COMMON_DEPENDS=	p5-DateTime>=0.10:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-TimeZone>=0.05:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-DateTime-Format-Builder>=0.72:${PORTSDIR}/devel/p5-DateTime-Format-Builder
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::Pg.3

.include <bsd.port.mk>

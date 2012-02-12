# New ports collection makefile for:	p5-DateTime-Format-ISO8601
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-ISO8601
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse ISO8601 formats

BUILD_DEPENDS=	p5-DateTime>=0.18:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0.77:${PORTSDIR}/devel/p5-DateTime-Format-Builder
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		DateTime::Format::ISO8601.3

.include <bsd.port.mk>

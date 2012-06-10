# New ports collection makefile for:	p5-DateTime-Format-Strptime
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Strptime
PORTVERSION=	1.50.00
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format strp and strf time patterns

RUN_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::Strptime.3

.include <bsd.port.mk>

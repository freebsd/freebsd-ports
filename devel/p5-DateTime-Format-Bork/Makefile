# New ports collection makefile for:	p5-DateTime-Format-Bork
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Bork
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Formats datetimes for that guy from The Muppet Show

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Builder.pm:${PORTSDIR}/devel/p5-DateTime-Format-Builder
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

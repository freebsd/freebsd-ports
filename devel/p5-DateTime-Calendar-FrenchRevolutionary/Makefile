# New ports collection makefile for:	p5-DateTime-Calendar-FrenchRevolutionary
# Date created:	   26 june 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-FrenchRevolutionary
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Dates in the French Revolutionary Calendar

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/Roman.pm:${PORTSDIR}/math/p5-Roman

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

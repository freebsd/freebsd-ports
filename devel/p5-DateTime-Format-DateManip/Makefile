# New ports collection makefile for:	p5-DateTime-Format-DateManip
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-DateManip
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Convert Date::Manip dates and durations to DateTimes and vice versa

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e '$$_ = "" if /^use bytes;/' ${WRKSRC}/lib/DateTime/Format/DateManip.pm
.endif

.include <bsd.port.post.mk>

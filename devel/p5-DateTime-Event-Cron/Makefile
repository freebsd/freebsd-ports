# New ports collection makefile for:	p5-DateTime-Event-Cron
# Date created:	   1 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-Cron
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DateTime extension for generating recurrence sets from crontab

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set \
		${SITE_PERL}/Set/Crontab.pm:${PORTSDIR}/devel/p5-Set-Crontab
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::Cron.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use (5.006|warnings)/g;' \
		     -e 's/->\$$_->l/->{\$$_}->/g;' \
		     ${WRKSRC}/lib/DateTime/Event/Cron.pm
.endif

.include <bsd.port.post.mk>

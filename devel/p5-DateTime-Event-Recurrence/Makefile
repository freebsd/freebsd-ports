# New ports collection makefile for:	p5-DateTime-Event-Recurrence
# Date created:	   1 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-Recurrence
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl DateTime extension for computing basic recurrences

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::Recurrence.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -p -i.orig -e 's/(\$$\w+(?:-\>)?{\s*(?:\$$?\w+|\$$\w+->{\w+}\[\$$\w+\])\s*})\(/\&{$$1}(/g;' \
		${WRKSRC}/lib/DateTime/Event/Recurrence.pm
.endif

.include <bsd.port.post.mk>

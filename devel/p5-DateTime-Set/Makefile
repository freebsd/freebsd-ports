# New ports collection makefile for:	p5-DateTime-Set
# Date created:	   26 june 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Set
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Datetime sets and set math

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/Set/Infinite.pm:${PORTSDIR}/devel/p5-Set-Infinite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Set.3 DateTime::Span.3 \
		DateTime::SpanSet.3

.include <bsd.port.pre.mk>

# Because p5-Set-Infinite needs 5.6.1
.if ${PERL_LEVEL} < 500601
IGNORE="Need at least perl 5.6.1 to build"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-DateTime-Functions
# Date created:	   8 Jan 2004
# Whom:		   Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Functions
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Procedural interface to DateTime functions

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Functions.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use 5.0/' ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>

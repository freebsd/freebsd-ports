# New ports collection makefile for:	devel/p5-Rose-DateTime
# Date created:				09 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Rose-DateTime
PORTVERSION=	0.531
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Rose
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	DateTime helper functions and objects

BUILD_DEPENDS=	${SITE_PERL}/Rose/Object.pm:${PORTSDIR}/devel/p5-Rose-Object \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Rose::DateTime.3 \
	Rose::DateTime::Parser.3 \
	Rose::DateTime::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>

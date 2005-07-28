# New ports collection makefile for:	p5-Encode
# Date created:				Jul 24, 2005
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	Encode
PORTVERSION=	2.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Encode
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Provides interfaces between strings and the rest of the system

PERL_CONFIGURE=	yes

MAN1=		piconv.1 enc2xs.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		Requires Perl 5.8.0 or above.
.elif ${PERL_LEVEL} > 500806
IGNORE=		Perl above 5.8.7 has Encode ${PORTVERSION}.
.endif

.include <bsd.port.post.mk>

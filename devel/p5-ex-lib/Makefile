# New ports collection makefile for:	p5-ex-lib
# Date created:		2009-01-23
# Whom:			Mons Anderson <mons@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	ex-lib
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Relative use lib in absolute way

PERL_CONFIGURE=	yes

MAN3=		ex::lib.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
BUILD_DEPENDS+=	p5-PathTools>=3.12:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS+=	p5-PathTools>=3.12:${PORTSDIR}/devel/p5-PathTools
.endif

.include <bsd.port.post.mk>

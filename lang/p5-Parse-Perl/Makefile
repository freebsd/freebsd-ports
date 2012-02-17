# New ports collection makefile for:	p5-Parse-Perl
# Date created:		2010-11-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-Perl
PORTVERSION=	0.007
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interpret string as Perl source

RUN_DEPENDS=	p5-Devel-CallChecker>=0:${PORTSDIR}/devel/p5-Devel-CallChecker
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Parse::Perl.3 \
		Parse::Perl::CopHintsHash.3 \
		Parse::Perl::Environment.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>

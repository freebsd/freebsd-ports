# New ports collection makefile for:	p5-Lexical-Var
# Date created:		2012-02-24
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lexical-Var
PORTVERSION=	0.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for static variables without namespace pollution

PERL_CONFIGURE=	yes

MAN3=	Lexical::Sub.3 Lexical::Var.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-ExtUtils-CBuilder>=0.1500:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Lexical-SealRequireHints>=0.006:${PORTSDIR}/devel/p5-Lexical-SealRequireHints
RUN_DEPENDS+=	p5-Lexical-SealRequireHints>=0.006:${PORTSDIR}/devel/p5-Lexical-SealRequireHints
.endif

post-patch:
.if ${PERL_LEVEL} >= 501200
	@${REINPLACE_CMD} -e '/Lexical::SealRequireHints/d' ${WRKSRC}/Build.PL ${WRKSRC}/lib/Lexical/Var.pm
.endif

.include <bsd.port.post.mk>

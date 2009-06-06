# New ports collection makefile for:	Lingua::JA::Regular::Unicode
# Date created:		06 Jun 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-JA-Regular-Unicode
PORTVERSION=	0.02
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to convert Japanese chars

#RUN_DEPENDS=
BUILD_DEPENDS=	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	yes

MAN3=	Lingua::JA::Regular::Unicode.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.if ${PERL_LEVEL} < 500801
IGNORE=		older perl not supported
.endif

.include <bsd.port.post.mk>

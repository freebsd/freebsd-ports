# New ports collection makefile for:	FSA-Rules
# Date created:				11 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FSA-Rules
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DW/DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Build simple rules-based state machines in Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		FSA::Rules.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires at least Perl5.6 due to dependencies
.endif

.include <bsd.port.post.mk>

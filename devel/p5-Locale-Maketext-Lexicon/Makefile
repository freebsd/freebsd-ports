# New ports collection makefile for:	p5-Locale-Maketext-Lexicon
# Date created:				February 23, 2003
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext-Lexicon
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Use other catalog formats in Locale::Maketext

BUILD_DEPENDS=	${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser \
		${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Locale::Maketext::Extract.3 \
		Locale::Maketext::Lexicon::Auto.3 \
		Locale::Maketext::Lexicon::Gettext.3 \
		Locale::Maketext::Lexicon::Msgcat.3 \
		Locale::Maketext::Lexicon::Tie.3 \
		Locale::Maketext::Lexicon.3

MAN1=		xgettext.pl.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500601
.if ${PERL_LEVEL} == 500601
BUILD_DEPENDS+=	${SITE_PERL}/Encode/compat.pm:${PORTSDIR}/devel/p5-Encode-compat
.else
IGNORE="Need at least perl 5.6.1 to build"
.endif
.endif

.include <bsd.port.post.mk>

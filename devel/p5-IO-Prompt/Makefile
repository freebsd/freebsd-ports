# New ports collection makefile for:	devel/p5-IO-Prompt
# Date created:				13 September 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Prompt
PORTVERSION=	0.99.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/D/DC/DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Interactively prompt for user input

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/Want.pm:${PORTSDIR}/devel/p5-Want
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	IO::Prompt.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
post-patch:
	@${PERL} -pi -e '$$_ = "" if m|use 5.008;|' \
		${WRKSRC}/lib/IO/Prompt.pm
.endif
.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>

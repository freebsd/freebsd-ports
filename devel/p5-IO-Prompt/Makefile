# New ports collection makefile for:	devel/p5-IO-Prompt
# Date created:				13 September 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Prompt
PORTVERSION=	0.99.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Interactively prompt for user input

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/Want.pm:${PORTSDIR}/devel/p5-Want
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	IO::Prompt.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>

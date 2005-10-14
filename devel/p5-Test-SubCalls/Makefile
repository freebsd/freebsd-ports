# New ports collection makefile for:	devel/p5-Test-SubCalls
# Date created:				08 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-SubCalls
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Track the number of times subs are called

BUILD_DEPENDS=	${SITE_PERL}/Hook/LexWrap.pm:${PORTSDIR}/devel/p5-Hook-LexWrap \
		${SITE_PERL}/Test/Builder/Tester.pm:${PORTSDIR}/devel/p5-Test-Builder-Tester
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::SubCalls.3

post-patch:
	@${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	@${PERL} -pi -e '$$_="" if m/AutoInstall/' ${WRKSRC}/MANIFEST
	@${PERL} -pi -e '$$_="" if m/Test::More|auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500601  # inherited from devel/p5-Hook-LexWrap
IGNORE=	requires perl 5.6.1 or newer. Install lang/perl5 or lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>

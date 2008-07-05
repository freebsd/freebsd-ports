# New ports collection makefile for:	p5-Games-Bingo
# Date created:				14. August 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Games-Bingo-Print
PORTVERSION=	0.04
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Games::Bingo::Print - PDF Generation Class

BUILD_DEPENDS=	${SITE_PERL}/Games/Bingo.pm:${PORTSDIR}/games/p5-Games-Bingo \
		${SITE_PERL}/PDFLib.pm:${PORTSDIR}/print/p5-PDFLib \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/TAP/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Perl/Critic.pm:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		bingo_print.pl.1
MAN3=		Games::Bingo::Print.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing example for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingo_print.pl ${EXAMPLESDIR}
.endif

test:
	@cd ${WRKSRC}; make test

.include <bsd.port.mk>

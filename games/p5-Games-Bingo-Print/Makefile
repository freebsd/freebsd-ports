# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Games-Bingo-Print
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Games::Bingo::Print - PDF Generation Class

BUILD_DEPENDS=	p5-Games-Bingo>=0:${PORTSDIR}/games/p5-Games-Bingo \
		p5-PDFLib>=0:${PORTSDIR}/print/p5-PDFLib \
		p5-Test-Harness>=0:${PORTSDIR}/devel/p5-Test-Harness \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	bingo_print.pl

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingo_print.pl ${STAGEDIR}${EXAMPLESDIR}

regression-test: build
	@cd ${WRKSRC} && ${MAKE} -s test

.include <bsd.port.mk>

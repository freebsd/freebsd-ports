# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Games-Bingo-Print
PORTVERSION=	0.04
PORTREVISION=	3
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Games::Bingo::Print - PDF Generation Class

LICENSE=	ART10

BUILD_DEPENDS=	p5-Games-Bingo>=0:games/p5-Games-Bingo \
		p5-PDFLib>=0:print/p5-PDFLib
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Harness>=0:devel/p5-Test-Harness \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	bingo_print.pl

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingo_print.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

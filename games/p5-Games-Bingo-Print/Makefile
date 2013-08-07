# New ports collection makefile for:	p5-Games-Bingo
# Date created:				14. August 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

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

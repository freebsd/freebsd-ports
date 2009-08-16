# New ports collection makefile for:    p5-Test-Tester
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-Tester
PORTVERSION=	0.10.7
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helps to test various Test::Builder derivatives

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Test::Tester.3 Test::Tester::Capture.3 \
		Test::Tester::CaptureRunner.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>

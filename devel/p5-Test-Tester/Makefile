# New ports collection makefile for:    p5-Test-Tester
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-Tester
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Helps to test various Test::Builder derivatives

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS=site
INSTALL_TARGET=	pure_install

MAN3=		Test::Tester.3 Test::Tester::Capture.3 \
		Test::Tester::CaptureRunner.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/Builder.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${BUILD_DEPENDS}
.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -pi -e '$$_ = "" if /(use|no) warnings/g;' \
		${WRKSRC}/lib/Test/Tester.pm ${WRKSRC}/lib/Test/Tester/Delegate.pm
.endif
.endif

.include <bsd.port.post.mk>

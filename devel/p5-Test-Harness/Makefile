# New ports collection makefile for:	p5-Test-Harness
# Date Created:				13 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Harness
PORTVERSION=	2.42
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Run perl standard test scripts with statistics

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN1=		prove.1
MAN3=		Test::Harness.3 Test::Harness::Assert.3 \
		Test::Harness::Iterator.3 Test::Harness::Straps.3

post-patch:
	${PERL} -pi -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS=	${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>

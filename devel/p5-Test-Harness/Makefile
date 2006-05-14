# New ports collection makefile for:	p5-Test-Harness
# Date Created:				13 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Harness
PORTVERSION=	2.58
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run perl standard test scripts with statistics

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN1=		prove.1
MAN3=		Test::Harness.3 Test::Harness::Assert.3 \
		Test::Harness::Iterator.3 Test::Harness::Point.3 \
		Test::Harness::Straps.3 Test::Harness::TAP.3 \
		Test::Harness::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

.if ${PERL_LEVEL} >= 500800
.undef MAN1
PLIST_SUB+=	PL_FILES="@comment "
.else
PLIST_SUB+=	PL_FILES=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/INSTALLDIRS/d' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
.if ${PERL_LEVEL} >= 500800
	@${REINPLACE_CMD} -E -e '/(DESTINSTALLSITEMAN1DIR|DESTINSTALLSCRIPT)/d' \
		${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>

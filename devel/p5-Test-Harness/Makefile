# New ports collection makefile for:	p5-Test-Harness
# Date Created:				13 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Harness
PORTVERSION=	2.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	shell@shellhung.org

PERL_CONFIGURE=	yes

MAN3=		Test::Harness.3 Test::Harness::Assert.3 \
		Test::Harness::Iterator.3 Test::Harness::Straps.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${PERL} -pi -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

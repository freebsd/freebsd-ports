# New ports collection makefile for:	p5-Test-Harness
# Date Created:				13 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Harness
PORTVERSION=	1.23
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	shell@shellhung.org

PERL_CONFIGURE=	yes

MODULE_PREFIX=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
CONFIGURE_ARGS+= INSTALLPRIVLIB=${MODULE_PREFIX} \
		 INSTALLARCHLIB=${MODULE_PREFIX}/${PERL_ARCH}

MAN3=		Test::Harness.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Expect
# Version required:	1.07
# Date created:		14 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	Expect.pm-1.07
PKGNAME=	p5-Expect-1.07
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Expect

MAINTAINER=	andrews@technologist.com

BUILD_DEPENDS=	${SITE_PERL}/IO-Tty.pm:${PORTSDIR}/devel/p5-IO-Tty \
		${SITE_PERL}/IO-Stty.pm:${PORTSDIR}/devel/p5-IO-Stty
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
USE_PERL5=	yes
MAN3=		Expect.3 Expect_intro.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL LDDLFLAGS=-shared LDFLAGS=-L/usr/lib)

.include <bsd.port.mk>

# New ports collection makefile for:	Jcode
# Version required:	0.60
# Date created:		7 Nov 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Jcode-0.60
PKGNAME=	ja-p5-Jcode-0.60
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DANKOGAI

MAINTAINER=	kuriyama@FreeBSD.org

USE_PERL5=	YES
USE_ZIP=	YES

MAN3=		Jcode.3 Jcode::Unicode.3 Jcode::Unicode::Constants.3 \
		Jcode::Unicode::NoXS.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>

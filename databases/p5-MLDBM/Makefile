# New ports collection makefile for:    p5-MLDBM
# Version required:                     2.00
# Date created:                         December 3 1997
# Whom:                                 ache@freebsd.org
#
# $FreeBSD$
#

DISTNAME=       MLDBM-2.00
PKGNAME=        p5-MLDBM-2.00
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     MLDBM

MAINTAINER=     ports@FreeBSD.org

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable

USE_PERL5=	YES

MAN3=           MLDBM.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>

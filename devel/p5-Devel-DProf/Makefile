# New ports collection makefile for:	p5-Devel-DProf
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DProf
PORTVERSION=	19990108
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-Devel-

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	yes

MAN1PREFIX=	${PREFIX}
MAN1=		dprofpp.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Devel::DProf.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			PREFIX="${PREFIX}" CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>

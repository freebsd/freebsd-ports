# New ports collection makefile for:    p5-Filter
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filter
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filter
PKGNAMEPREFIX=	p5-

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Filter::Util::Call.3 Filter::Util::Exec.3 Filter::cpp.3 \
		Filter::decrypt.3 Filter::exec.3 Filter::sh.3 Filter::tee.3 \
		perlfilter.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			CC="${CC}" CCFLAGS="${CFLAGS}"
		@${PERL} -i -p \
			-e 's/^(CC = ).*/$$1 ${CC}/;' \
			-e 's/^(CCFLAGS = ).*/$$1 ${CFLAGS}/' \
			`find ${WRKSRC} -name Makefile`

.include <bsd.port.mk>

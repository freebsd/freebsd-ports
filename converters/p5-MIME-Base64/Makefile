# New ports collection makefile for:    p5-MIME-Base64
# Date created:                         June 21th 1997
# Whom:                                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	MIME-Base64
PORTVERSION=	2.11
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME
PKGNAMESUFFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	YES

MAN3=		MIME::Base64.3 \
		MIME::QuotedPrint.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-build:
	@${PERL} -pi -e "s:-O -pipe:${CFLAGS}:g" ${WRKSRC}/Makefile.PL
	@${PERL} -pi -e "s:cc:${CC}:g" ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Convert-ASN1
# Date created:				October 27, 2000
# Whom:	      				Marc Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Convert-ASN1
PORTVERSION=	0.07
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	scrappy@FreeBSD.org

USE_PERL5=	YES

MAN3=		Convert::ASN1.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			PREFIX=${PREFIX}

.include <bsd.port.mk>

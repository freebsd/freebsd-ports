# New ports collection makefile for:	p5-Convert-UUlib
# Date created:				November 19th 2000
# Whom:					Blaz Zupan <blaz@amis.net>
#
# $FreeBSD$
#

PORTNAME=	Convert-UUlib
PORTVERSION= 	0.11
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	blaz@amis.net

USE_PERL5=	yes

MAN3=		Convert::UUlib.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>

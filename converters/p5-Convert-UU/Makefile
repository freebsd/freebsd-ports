# New ports collection makefile for:	p5-Convert-UU
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Convert-UU
PORTVERSION=	0.40
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
DISTNAME=	Convert-UU-${PORTVERSION}

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

.include <bsd.port.pre.mk>

MAN1=		puuencode.1 puudecode.1
MAN3=		Convert::UU.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PREFIX=${PREFIX}

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-MP3-ID3v1Tag
# Date created:		13-Aug-2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	MP3-ID3v1Tag
PORTVERSION=	1.10
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=MP3
PKGNAMEPREFIX=	p5-

MAINTAINER=	leo@florida.sarang.net

USE_PERL5=	YES
MAN3=		MP3::ID3v1Tag.3 MPEG::ID3v1Tag.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>

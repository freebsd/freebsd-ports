# New ports collection makefile for:	p5-libvorbis
# Date created:		30 Jul 2002
# Whom:			Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=../by-authors/id/F/FO/FOOF
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Perl extension for Ogg Vorbis streams

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

USE_REINPLACE=	yes

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Ogg::Vorbis.3

post-extract:
	@${RM} -rf ${WRKSRC}/blib ${WRKSRC}/pm_to_blib

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

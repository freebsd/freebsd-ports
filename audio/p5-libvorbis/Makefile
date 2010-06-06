# New ports collection makefile for:	p5-libvorbis
# Date created:		30 Jul 2002
# Whom:			Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	0.05
PORTREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/F/FO/FOOF
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for Ogg Vorbis streams

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis


PERL_CONFIGURE=	yes

MAN3=		Ogg::Vorbis.3

post-extract:
	@${RM} -rf ${WRKSRC}/blib ${WRKSRC}/pm_to_blib

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

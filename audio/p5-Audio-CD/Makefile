# New ports collection makefile for:	p5-Audio-CD
# Date created:				22 Oct 2000
# Whom:	      				Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	Audio-CD
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Audio
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@oven.org
COMMENT=	Perl interface to libcdaudio (cd + cddb)

LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio

PERL_CONFIGURE=	YES
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include " \
		LIBS="-L${LOCALBASE}/lib -lcdaudio"

MAN3=		Audio::CD.3

.include <bsd.port.mk>

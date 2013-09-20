# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	Audio-CD
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to libcdaudio (cd + cddb)

LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio

USES=		perl5
NO_STAGE=	yes
USE_PERL5=	configure
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include " \
		LIBS="-L${LOCALBASE}/lib -lcdaudio"

MAN3=		Audio::CD.3

.include <bsd.port.mk>

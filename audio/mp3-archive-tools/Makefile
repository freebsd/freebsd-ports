# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	mp3-archive-tools
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://erislabs.net/ianb/projects/mp3-archive-tools/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of tools to ease organising a collection of audio files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	libmp3-archive-perl>=0:audio/libmp3-archive-perl \
		p5-MP3-Tag>=0:audio/p5-MP3-Tag

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

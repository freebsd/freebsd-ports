# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	Ogg-Vorbis-Header
PORTVERSION=	0.03
PORTREVISION=	4
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulate / fetch info from Ogg-Vorbis audio files

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline
LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
NO_STAGE=	yes
USE_PERL5=	configure

MAN3=		Ogg::Vorbis::Header.3

.include <bsd.port.mk>

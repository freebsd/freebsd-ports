PORTNAME=	midi-matrix
DISTVERSION=	0.28.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://git.open-music-kontrollers.ch/lv2/midi_matrix.lv2/snapshot/
PKGNAMESUFFIX=	-lv2
DISTNAME=	midi_matrix.lv2-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 'Midi Matrix' plugin bundle: 'Channel Filter'
WWW=		https://open-music-kontrollers.ch/lv2/midi_matrix/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint \
		sord_validate:devel/sord

USES=		compiler:c11 gl meson pkgconfig tar:xz xorg
USE_XORG=	x11 xext
USE_GL=		gl glew glu

.include <bsd.port.mk>

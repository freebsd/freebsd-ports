# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	midi-matrix
DISTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.com/OpenMusicKontrollers/midi_matrix.lv2/repository/archive.tar.gz?ref=${DISTVERSION}&dummy=/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 'Midi Matrix' plugin bundle: 'Channel Filter'

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint \
		sord_validate:devel/sord

USES=		compiler:c11 gl meson pkgconfig xorg
USE_XORG=	x11 xext
USE_GL=		gl glu

post-extract:
	@${MV} ${WRKDIR}/midi_matrix* ${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>

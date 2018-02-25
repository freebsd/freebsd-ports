# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	midi-matrix
PORTVERSION=	0.20.0
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.com/OpenMusicKontrollers/midi_matrix.lv2/repository/archive.tar.gz?ref=${PORTVERSION}&dummy=/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 'Midi Matrix' plugin bundle: 'Channel Filter'

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		cmake pkgconfig
USE_XORG=	x11 xext
USE_GL=		gl glu

post-extract:
	@${MV} ${WRKDIR}/midi_matrix* ${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>

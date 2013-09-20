# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmp-htmlplaylist
PORTVERSION=	0.2.1
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/bmp-plugins/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Application which saves your current BMP playlist to html or xml file

BUILD_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
RUN_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player

NO_STAGE=	yes
MAKE_ARGS=	CC="${CC}" LD="${CC}"
USES=	pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes

PLIST_FILES=	bin/bmp-htmlplaylist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmp-htmlplaylist ${PREFIX}/bin/

.include <bsd.port.mk>

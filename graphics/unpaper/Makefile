PORTNAME=	unpaper
PORTVERSION=	6.1
CATEGORIES=	graphics
MASTER_SITES=	https://www.flameeyes.eu/files/

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Post-processing tool for scanned sheets of paper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt \
		bash:shells/bash
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg

USES=		autoreconf pkgconfig tar:xz

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>

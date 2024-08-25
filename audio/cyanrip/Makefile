PORTNAME=	cyanrip
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/cyanreg/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME}-src-${DISTVERSIONFULL}

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Audio CD ripper with command-line interface and focus on accuracy
WWW=		https://github.com/cyanreg/cyanrip

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcdio.so:sysutils/libcdio \
		libcdio_paranoia.so:sysutils/libcdio-paranoia \
		libcurl.so:ftp/curl \
		libmusicbrainz5.so:audio/libmusicbrainz5

USES=		localbase meson pkgconfig

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cyanrip

.include <bsd.port.mk>

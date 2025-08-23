PORTNAME=	cyanrip
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://github.com/cyanreg/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME}-src-${DISTVERSIONFULL}

PATCH_SITES=	https://github.com/cyanreg/cyanrip/commit/
PATCHFILES=	70c0a4c04d5ce74135719cf8afc1309b29679395.patch:-p1 \
		8cae5f548a606bfd723fbcfccabcd5da189063cb.patch:-p1 \
		462a71c75b4d326c0ce787cd13f7048e7f5da630.patch:-p1 \
		7f74e52f278fd9d8474b1afb5979b9ecd525285e.patch:-p1

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

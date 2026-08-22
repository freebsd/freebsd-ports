PORTNAME=	cyanrip
#DISTVERSIONPREFIX=	v
#DISTVERSION=	0.9.3.1
DISTVERSION=	0.9.4-rc2.20260821
CATEGORIES=	audio
#MASTER_SITES=	https://github.com/cyanreg/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
#DISTNAME=	${PORTNAME}-src-${DISTVERSIONFULL}

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Audio CD ripper with command-line interface and focus on accuracy
WWW=		https://github.com/cyanreg/cyanrip

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcdio.so:sysutils/libcdio \
		libcdio_paranoia.so:sysutils/libcdio-paranoia \
		libcurl.so:ftp/curl \
		libmusicbrainz5.so:audio/libmusicbrainz5 \
		libqrencode.so:graphics/libqrencode

USES=		localbase:ldflags meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	cyanreg
GH_TAGNAME=	f8ebf48fc0d6926796c785fe2dbd9dec54ac15a5

#NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cyanrip \
		share/metainfo/com.github.cyanreg.cyanrip.metainfo.xml

.include <bsd.port.mk>

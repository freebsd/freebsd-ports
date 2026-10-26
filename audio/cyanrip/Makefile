PORTNAME=	cyanrip
#DISTVERSIONPREFIX=	v
#DISTVERSION=	0.9.3.1
DISTVERSION=	0.9.4-rc3.20261016
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
		libchromaprint.so:audio/chromaprint \
		libcurl.so:ftp/curl \
		libmusicbrainz5.so:audio/libmusicbrainz5 \
		libqrencode.so:graphics/libqrencode

USES=		localbase:ldflags meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	cyanreg
GH_TAGNAME=	7dbe56aad2f0ab039ab7b238a30ed662b1c017de

#NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cyanrip \
		share/metainfo/com.github.cyanreg.cyanrip.metainfo.xml

.include <bsd.port.mk>

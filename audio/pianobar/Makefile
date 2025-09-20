PORTNAME=	pianobar
DISTVERSION=	2024.12.21
CATEGORIES=	audio

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Command-line Pandora online radio player
WWW=		https://6xq.net/pianobar/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c \
		libgcrypt.so:security/libgcrypt \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl

USES=		alias gmake localbase pkgconfig tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	PromyLOPh

MAKE_ENV+=	V=1

PLIST_FILES=	bin/pianobar \
		share/man/man1/pianobar.1.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pianobar

.include <bsd.port.mk>

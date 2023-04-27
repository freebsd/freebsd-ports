PORTNAME=	pianobar
PORTVERSION=	2022.04.01
PORTREVISION=	2
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

MAKE_ENV+=	V=1
USES=		alias gmake localbase pkgconfig tar:bzip2

PLIST_FILES=	bin/pianobar \
		man/man1/pianobar.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	PromyLOPh

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pianobar

.include <bsd.port.mk>

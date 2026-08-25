PORTNAME=	alacenc
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Apple Lossless Audio Codec (ALAC) format encoder
WWW=		https://github.com/flacon/alacenc

LICENSE=	MIT

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	flacon

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${FIND} ${WRKSRC} -type f -name CMakeLists.txt -print0 | ${XARGS} \
		-0 ${REINPLACE_CMD} -e '/cmake_minimum_required(VERSION/ \
			s,3\.[0-9],&...9.9,'

.include <bsd.port.mk>

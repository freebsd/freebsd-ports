PORTNAME=	rsgain
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	ReplayGain 2.0 tagging utility
WWW=		https://github.com/complexlogic/rsgain

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libebur128.so:audio/libebur128 \
		libtag.so:audio/taglib \
		libfmt.so:devel/libfmt \
		libinih.so:devel/inih \
		libavcodec.so:multimedia/ffmpeg

USES=		cmake compiler:c++2b-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	complexlogic

CXXFLAGS+=	-pthread

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

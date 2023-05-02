PORTNAME=	rsgain
DISTVERSION=	3.3
DISTVERSIONSUFFIX=	-source
CATEGORIES=	audio
MASTER_SITES=	https://github.com/complexlogic/rsgain/releases/download/v${DISTVERSION}/

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

USES=		cmake compiler:c++2b-lang pkgconfig tar:xz

CMAKE_ARGS=	-DMAXPROGBARWIDTH=80
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=		DOCS UNICODE
OPTIONS_DEFAULT=	UNICODE

UNICODE_CMAKE_BOOL=	UCHECKMARKS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

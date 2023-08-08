PORTNAME=	flac123
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Command-line player for flac audio files
WWW=		https://github.com/flac123/flac123

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libao.so:audio/libao \
		libpopt.so:devel/popt \
		libogg.so:audio/libogg

USES=		autoreconf cpe
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.remote

PLIST_FILES=	bin/flac123 \
		man/man1/flac123.1.gz

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

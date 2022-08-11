PORTNAME=	cfdg
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	graphics math
MASTER_SITES=	http://www.contextfreeart.org/download/ \
		http://glyphic.s3.amazonaws.com/cfa/download/
DISTNAME=	ContextFreeSource${PORTVERSION}

MAINTAINER=	fuz@fuz.su
COMMENT=	Context Free Design Grammar compiler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpng.so:graphics/png

USES=		bison gmake tar:xz
MAKE_ARGS=	prefix=${PREFIX} \
		DESTDIR=${STAGEDIR}
TEST_TARGET=	check
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/cfdg \
		share/man/man1/cfdg.1.gz

PORTEXAMPLES=	*.cfdg

OPTIONS_DEFINE=	EXAMPLES FFMPEG
OPTIONS_DEFAULT=	FFMPEG
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
			libx264.so:multimedia/libx264
FFMPEG_MAKE_ARGS=	WANT_FFMPEG=yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' ${WRKSRC}/Makefile

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/input/*.cfdg ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

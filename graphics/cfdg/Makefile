PORTNAME=	cfdg
DISTVERSION=	3.4.1
PORTREVISION=	4
CATEGORIES=	graphics math
MASTER_SITES=	http://www.contextfreeart.org/download/ \
		http://glyphic.s3.amazonaws.com/cfa/download/
DISTNAME=	ContextFreeSource${DISTVERSION}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Context Free Design Grammar compiler
WWW=		https://www.contextfreeart.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpng.so:graphics/png

USES=		bison gmake tar:xz
MAKE_ARGS=	prefix=${PREFIX} \
		DESTDIR=${STAGEDIR}
TEST_TARGET=	check
CXXFLAGS+=	-Wno-register

# graphics/agg cannot be unbundled: version in ports too outdated
# furthermore, its header files conflict with the headers bundled by cfdg
CONFLICTS_BUILD=	agg

WRKSRC=		${WRKDIR}/context-free${DISTVERSION}
PLIST_FILES=	bin/cfdg \
		share/man/man1/cfdg.1.gz

PORTEXAMPLES=	*.cfdg

OPTIONS_DEFINE=	EXAMPLES FFMPEG
OPTIONS_DEFAULT=	FFMPEG
FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
			libx264.so:multimedia/libx264
FFMPEG_MAKE_ARGS=	WANT_FFMPEG=yes

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/Makefile

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/input/*.cfdg ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

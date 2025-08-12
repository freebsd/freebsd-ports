PORTNAME=	id3edit
PORTVERSION=	2.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI tool to edit and debug ID3v2 tags of mp3 files
WWW=		https://github.com/rstemmer/id3edit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprinthex.so:devel/libprinthex

USES=		iconv localbase:ldflags

CFLAGS+=	-DVERSION="\"${PORTVERSION}\"" -Wno-multichar
LDFLAGS+=	-lprinthex -lz

PLIST_FILES=	bin/id3dump \
		bin/id3edit \
		bin/id3frames \
		bin/id3show

FILES=		crc32 extheader frameflags id3v2 id3v2frame main rawfile \
		encoding/crc encoding/size encoding/text

USE_GITHUB=	yes
GH_ACCOUNT=	rstemmer

do-build:
.for file in ${FILES}
	@${CC} ${CFLAGS} -I${WRKSRC} -c ${WRKSRC}/${file}.c -o ${WRKSRC}/${file}.o
.endfor
	@${CC} ${LDFLAGS} ${FILES:C|.*|${WRKSRC}/&.o|} -o ${WRKSRC}/id3edit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/id3dump ${STAGEDIR}${PREFIX}/bin/id3dump
	${INSTALL_PROGRAM} ${WRKSRC}/id3edit ${STAGEDIR}${PREFIX}/bin/id3edit
	${INSTALL_SCRIPT} ${WRKSRC}/id3frames ${STAGEDIR}${PREFIX}/bin/id3frames
	${INSTALL_SCRIPT} ${WRKSRC}/id3show ${STAGEDIR}${PREFIX}/bin/id3show

.include <bsd.port.mk>

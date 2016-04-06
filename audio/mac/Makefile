# Created by: Martin Dieringer <Martin.Dieringer@t-online.de>
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	3.99.4.5.7
CATEGORIES=	audio
MASTER_SITES=	http://etree.org/shnutils/shntool/support/formats/ape/unix/3.99-u4-b5-s7/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}-3.99-u4-b5-s7

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Monkey's Audio lossless codec

USES=		iconv:build libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-DSHNTOOL

PORTDOCS=	Credits.txt History.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
BUILD_DEPENDS+=	yasm:devel/yasm
.endif
.endif

post-install:
	cd ${WRKSRC}/src/MACLib && ${INSTALL_DATA} BitArray.h \
		Prepare.h UnBitArrayBase.h ${STAGEDIR}${PREFIX}/include/mac
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
# Install couple of useful docfiles, but first beautify them a bit; cryptic
# sed(1) construct is to append missing newline at EOF, in a way compatible
# with both GNU and BSD sed(1) implementations.
	${ICONV_CMD} -f latin1 -t utf-8 ${WRKSRC}/src/Credits.txt | \
		${SED} -ne '$$G;P' > ${STAGEDIR}${DOCSDIR}/Credits.txt
	${SED} -ne '$$G;P' ${WRKSRC}/src/History.txt > \
		${STAGEDIR}${DOCSDIR}/History.txt

.include <bsd.port.post.mk>

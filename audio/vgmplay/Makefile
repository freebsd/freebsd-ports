# $FreeBSD$

PORTNAME=	vgmplay
PORTVERSION=	0.40.9
CATEGORIES=	audio
MASTER_SITES=	https://github.com/vgmrips/${PORTNAME}/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/vgmp/VGMP/}_${PORTVERSION:S/.//:S/./-/}_src

MAINTAINER=	tagattie@yandex.com
COMMENT=	Command-line player for VGM (video game music) files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/licenses/GPL.txt

USES=		7z compiler dos2unix gmake

NO_WRKSUBDIR=	yes

OPTIONS_SINGLE=	AUDIO
OPTIONS_SINGLE_AUDIO=	OSS LIBAO
OPTIONS_DEFAULT=	OSS

OSS_DESC=	Use OSS (/dev/dsp)
LIBAO_DESC=	Use libao

OSS_MAKE_ENV+=	USE_LIBAO=0
LIBAO_MAKE_ENV+=	USE_LIBAO=1
LIBAO_LIB_DEPENDS=	libao.so:audio/libao
LIBAO_CFLAGS+=	-I${LOCALBASE}/include
LIBAO_LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	PREFIX=${LOCALBASE}

PLIST_FILES=	bin/vgmplay bin/vgm2pcm bin/vgm2wav man/man1/vgmplay.1.gz ${EXAMPLESDIR}/vgmplay.ini

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's/@//' ${WRKSRC}/Makefile
.if ${CHOSEN_COMPILER_TYPE} != clang
	${REINPLACE_CMD} -e 's/-Wno-unused-but-set-variable//' ${WRKSRC}/Makefile
.endif
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; s|/usr/share/vgmplay|${EXAMPLESDIR}|; s|VGMPlay|vgmplay|g;' ${WRKSRC}/vgmplay.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vgmplay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vgm2pcm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vgm2wav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vgmplay.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/VGMPlay.ini ${STAGEDIR}${EXAMPLESDIR}/vgmplay.ini

.include <bsd.port.post.mk>

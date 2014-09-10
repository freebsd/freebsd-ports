# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemenu
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/advancemame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for AdvanceMAME, MAME, MESS, RAINE

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		gmake
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-svgalib --disable-fb --disable-alsa --enable-oss \
		--disable-slang --disable-ncurses --disable-kevent

CFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
PLIST_FILES=	bin/advmenu man/man1/advmenu.1.gz

OPTIONS_DEFINE=		DOCS FREETYPE
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT=	FREETYPE
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
ASM_CONFIGURE_ENABLE=	asm
FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@@|@|' ${WRKSRC}/Makefile.in

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} advmenu \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} advmenu.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in HISTORY README RELEASE
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} advmenu.[ht]* \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

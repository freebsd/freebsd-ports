# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemenu
PORTVERSION=	2.8
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/amadvance/advancemame/releases/download/${DISTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for AdvanceMAME, MAME, MESS, RAINE

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:textproc/expat2

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

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_USE=		gcc=any
ASM_CONFIGURE_ENABLE=	asm
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype

MAKE_JOBS_UNSAFE=	yes

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
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README RELEASE \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} advmenu.[ht]* \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

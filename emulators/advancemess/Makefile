# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemess
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/amadvance/advancemame/releases/download/${DISTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL MESS port with advanced TV and monitor video support

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2
RUN_DEPENDS=	advancemame>=1.4:emulators/advancemame

USES=		gmake ncurses sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-svgalib --disable-fb --disable-alsa --enable-oss \
		--disable-kevent

CFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
PLIST_FILES=	bin/advmess \
		man/man1/advmess.1.gz \
		share/advance/sysinfo.dat

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FREETYPE SLANG DOCS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT=	FREETYPE
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_USE=		gcc=any
ASM_CONFIGURE_ENABLE=	asm
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_ENABLE=	slang
SLANG_LDFLAGS=		-lncurses

BROKEN_powerpc=		Does not compile on powerpc

post-patch:
	@${REINPLACE_CMD} -e \
		's|@@|@|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/WHOLE_CFLAGS_OPT/s|-O2|| ; \
		 /WHOLE_LDFLAGS/s|-s||' ${WRKSRC}/advance/advance.mak
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/advance/emu.mak

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} advmess \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/support && ${INSTALL_MAN} advmess.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/advance
	(cd ${WRKSRC}/support && ${INSTALL_DATA} sysinfo.dat \
		${STAGEDIR}${PREFIX}/share/advance)

.include <bsd.port.mk>

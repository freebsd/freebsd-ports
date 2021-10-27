# Created by: alepulver

PORTNAME=	advancemenu
PORTVERSION=	2.8
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/amadvance/advancemame/releases/download/${DISTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for AdvanceMAME, MAME, MESS, RAINE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake localbase:ldflags sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-svgalib --disable-fb --disable-alsa --enable-oss \
		--disable-slang --disable-ncurses --disable-kevent

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/advmenu man/man1/advmenu.1.gz

OPTIONS_DEFINE=		DOCS FREETYPE
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT=	FREETYPE
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_USE=		GCC=yes
ASM_CONFIGURE_ENABLE=	asm
FREETYPE_USES=		pkgconfig
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype

DEPRECATED=	Heavily outdated and unmaintained
EXPIRATION_DATE=	2021-10-31

BINARY_ALIAS=		freetype-config=${WRKSRC}/freetype-config-dummy

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@@|@|' ${WRKSRC}/Makefile.in
	# Mock freetype-config script
	echo -e '#!/bin/sh\npkg-config freetype2 $$*' >> ${WRKSRC}/freetype-config-dummy
	chmod +x ${WRKSRC}/freetype-config-dummy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/advmenu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/advmenu.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README RELEASE \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/advmenu.[ht]* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

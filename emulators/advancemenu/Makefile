# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemenu
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/advancemame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for AdvanceMAME, MAME, MESS, RAINE

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USE_SDL=	sdl
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-asm --disable-svgalib --disable-fb \
		--disable-alsa --enable-oss --disable-slang \
		--disable-ncurses --disable-kevent

CFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
PLIST_FILES=	bin/advmenu man/man1/advmenu.1.gz

OPTIONS_DEFINE=	FREETYPE DOCS
OPTIONS_DEFAULT=FREETYPE

FREETYPE_CONFIGURE_ENABLE=	freetype
FREETYPE_LIB_DEPENDS=		libfreetype.so:${PORTSDIR}/print/freetype2

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@@|@|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/\(pkgdocdir\)/s|^|#| ; \
		 /WHOLE_CFLAGS_OPT/s|-O2|| ; \
		 /WHOLE_LDFLAGS/s|-s||' ${WRKSRC}/advance/advance.mak

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} advmenu ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} advmenu.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README RELEASE \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} advmenu.[ht]* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

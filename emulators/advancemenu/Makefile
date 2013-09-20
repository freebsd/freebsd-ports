# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemenu
PORTVERSION=	2.6
CATEGORIES=	emulators
MASTER_SITES=	SF/advancemame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for AdvanceMAME, MAME, MESS, RAINE

LICENSE=	GPLv2

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	FREETYPE DOCS
OPTIONS_DEFAULT=FREETYPE

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-asm --disable-svgalib --disable-fb \
		--disable-alsa --enable-oss --disable-slang \
		--disable-ncurses --disable-kevent

CFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		advmenu.1
PORTDOCS=	*
PLIST_FILES=	bin/advmenu

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=--disable-freetype
.endif

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
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} advmenu ${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} advmenu.1 ${MANPREFIX}/man/man1)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in HISTORY README RELEASE
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} advmenu.[ht]* ${DOCSDIR})
.endif

.include <bsd.port.mk>

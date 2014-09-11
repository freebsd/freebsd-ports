# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemame
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL MAME port with advanced TV and monitor video support

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USE_SDL=	sdl
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-asm --disable-svgalib --disable-fb \
		--disable-alsa --enable-oss --disable-slang \
		--disable-ncurses --disable-kevent

DATADIR=	${PREFIX}/share/advance

CFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN_FILES=	advdev.1 advj.1 advk.1 advm.1 advmame.1 advs.1
PORTDOCS=	*

OPTIONS_DEFINE=	FREETYPE DOCS
OPTIONS_DEFAULT=FREETYPE

FREETYPE_CONFIGURE_ENABLE=	freetype
FREETYPE_LIB_DEPENDS=		libfreetype.so:${PORTSDIR}/print/freetype2

BROKEN_powerpc=		Does not compile on powerpc

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@@|@|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/\(pkgdocdir\)/s|^|#| ; \
		 /WHOLE_CFLAGS_OPT/s|-O2|| ; \
		 /WHOLE_LDFLAGS/s|-s||' ${WRKSRC}/advance/advance.mak
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/advance/emu.mak

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} advj advk advm advmame advs \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN_FILES} \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/support && ${INSTALL_DATA} *.dat ${STAGEDIR}${DATADIR})
.for i in artwork diff image rom sample snap
	@${MKDIR} ${STAGEDIR}${DATADIR}/${i}
	@${ECHO_CMD} -n > ${STAGEDIR}${DATADIR}/${i}/.keep_me
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README RELEASE \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.[ht]* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

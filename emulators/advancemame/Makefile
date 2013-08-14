# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemame
PORTVERSION=	1.2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL MAME port with advanced TV and monitor video support

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

DATADIR=	${PREFIX}/share/advance

CFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		advdev.1 advj.1 advk.1 advm.1 advmame.1 advs.1
PORTDOCS=	*
PLIST_FILES=	bin/advj \
		bin/advk \
		bin/advm \
		bin/advmame \
		bin/advs \
		%%DATADIR%%/artwork/.keep_me \
		%%DATADIR%%/diff/.keep_me \
		%%DATADIR%%/event.dat \
		%%DATADIR%%/history.dat \
		%%DATADIR%%/hiscore.dat \
		%%DATADIR%%/image/.keep_me \
		%%DATADIR%%/rom/.keep_me \
		%%DATADIR%%/sample/.keep_me \
		%%DATADIR%%/snap/.keep_me
PLIST_DIRS=	%%DATADIR%%/snap \
		%%DATADIR%%/sample \
		%%DATADIR%%/rom \
		%%DATADIR%%/image \
		%%DATADIR%%/diff \
		%%DATADIR%%/artwork \
		%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=--disable-freetype
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
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
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/advance/emu.mak

do-install:
.for i in advj advk advm advmame advs
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${PREFIX}/bin)
.endfor
.for i in ${MAN1}
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${i} ${MANPREFIX}/man/man1)
.endfor
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/support && ${INSTALL_DATA} *.dat ${DATADIR})
.for i in artwork diff image rom sample snap
	@${MKDIR} ${DATADIR}/${i}
	@${ECHO_CMD} -n > ${DATADIR}/${i}/.keep_me
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in HISTORY README RELEASE
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.[ht]* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>

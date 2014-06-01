# Created by: Stijn Hoop <stijn@win.tue.nl>
# $FreeBSD$

PORTNAME=	zsnes
PORTVERSION=	1.51
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ZSNES%20v${PORTVERSION}
DISTNAME=	zsnes${PORTVERSION:S/.//}src

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Intel x86 only Super Nintendo Entertainment System (SNES) Emulator

# This must be >= 0.98!
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	non-portable, for a portable emulator see emulators/snes9x

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/}/src

NO_OPTIONS_SORT=yes
OPTIONS_DEFINE=	X11 OPENGL DEBUGGER JMA AO
OPTIONS_DEFAULT=X11 JMA
DEBUGGER_DESC=	ZSNES Debugger
JMA_DESC=	JMA support

USE_SDL=	sdl
USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-cpucheck

PLIST_FILES=	bin/zsnes man/man1/zsnes.1.gz

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUGGER}
CONFIGURE_ARGS+=	--enable-debugger
.else
CONFIGURE_ARGS+=	--disable-debugger
.endif

.if ${PORT_OPTIONS:MJMA}
CONFIGURE_ARGS+=	--enable-jma
.else
CONFIGURE_ARGS+=	--disable-jma
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
CONFIGURE_ARGS+=	--enable-opengl
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif

.if ${PORT_OPTIONS:MAO}
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=	--enable-libao
.else
CONFIGURE_ARGS+=	--disable-libao
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@CXX@ @CFLAGS@ -o|@CXX@ @CXXFLAGS@ @CPPFLAGS@ -o|g ; \
		 s|@CC@ @CFLAGS@ -o|@CC@ @CFLAGS@ @CPPFLAGS@ -o|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -i "" -e \
		's|-O3||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zsnes ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/linux/zsnes.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

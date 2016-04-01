# Created by: Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	snes9x
PORTVERSION=	1.51
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://files.ipherswipsite.com/snes9x/ \
		http://www.lysator.liu.se/snes9x/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

LIB_DEPENDS=	libpng.so:graphics/png

USE_XORG=	x11 sm ice xext
USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-extensions
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	INCLUDES="-I${WRKSRC}/unzip -I${WRKSRC} -I${LOCALBASE}/include" \
		LDLIBS="-lpthread -L${LOCALBASE}/lib" \
		OPTIMISE="${CXXFLAGS}"
WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG OPENGL SCREENSHOT JMA NETPLAY DOCS
OPTIONS_DEFINE_i386=	ASM MMX
OPTIONS_DEFAULT_i386=	MMX
OPTIONS_DEFAULT=	SCREENSHOT JMA NETPLAY

SCREENSHOT_DESC=	Enable screenshot support
MMX_DESC=	Enable MMX
JMA_DESC=	Enable JMA archive decompression support
NETPLAY_DESC=	Enable network support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	controls.txt control-inputs.txt  changes.txt hardware.txt \
		porting.html faqs.txt snapshots.txt snes9x.conf.default \
		README
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--with-debug
.else
CONFIGURE_ARGS+=	--without-debug
.endif

.if ${ARCH} == "i386"
.if ${PORT_OPTIONS:MX86_ASM}
BUILD_DEPENDS+=	nasm:devel/nasm
CONFIGURE_ARGS+=	--with-assembler
.else
CONFIGURE_ARGS+=	--without-assembler
.endif

.if ${PORT_OPTIONS:MMMX} && !defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--with-mmx
.else
CONFIGURE_ARGS+=	--without-mmx
.endif
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
CONFIGURE_ARGS+=	--with-opengl
SNES9X_BIN=	osnes9x
.else
SNES9X_BIN=	snes9x
.endif

.if ${PORT_OPTIONS:MSCREENSHOT}
CONFIGURE_ARGS+=	--with-screenshot
.else
CONFIGURE_ARGS+=	--without-screenshot
.endif

.if ${PORT_OPTIONS:MJMA}
CONFIGURE_ARGS+=	--with-jma-decomp
.else
CONFIGURE_ARGS+=	--without-jma-decomp
.endif

.if ${PORT_OPTIONS:MNETPLAY}
CONFIGURE_ARGS+=	--with-netplay
.else
CONFIGURE_ARGS+=	--without-netplay
.endif

.if exists(/usr/lib/libusbhid.a)
CONFIGURE_ARGS+=	--with-joystick
.else
CONFIGURE_ARGS+=	--without-joystick
.endif

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|Pitch2|Pitch|g' ${WRKSRC}/unix/opengl.cpp

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in control* changes.txt hardware.txt porting.html faqs.txt \
		snapshots.txt snes9x.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/unix/docs/readme_unix.txt ${STAGEDIR}${DOCSDIR}/README
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/${SNES9X_BIN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>

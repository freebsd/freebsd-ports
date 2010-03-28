# New ports collection makefile for:    snes9x
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	snes9x
PORTVERSION=	1.51
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://files.ipherswipsite.com/snes9x/ \
		http://www.geocities.co.jp/SiliconValley-PaloAlto/2560/release/ \
		http://www.lysator.liu.se/snes9x/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_XORG=	x11 sm ice xext
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-extensions
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	INCLUDES="-I${WRKSRC}/unzip -I${WRKSRC} -I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}" LDLIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		OPTIMISE="${CXXFLAGS}"
WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS=	DEBUG	"Enable debug information"	off \
		OPENGL	"Enable OpenGL support"	off \
		SCREENSHOT	"Enable screenshot support"	on \
		X86_ASM	"Use i386 optimization (only for i386)"	on \
		MMX	"Enable MMX (only for i386)"	off \
		JMA	"Enable JMA archive decompression support"	on \
		NETPLAY	"Enable network support"	on

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	controls.txt control-inputs.txt  changes.txt hardware.txt \
		porting.html faqs.txt snapshots.txt snes9x.conf.default \
		README
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug
.else
CONFIGURE_ARGS+=	--without-debug
.endif

.if ${ARCH} == "i386"
.if !defined(WITHOUT_X86_ASM)
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-assembler
.else
CONFIGURE_ARGS+=	--without-assembler
.endif

.if defined(WITH_MMX) && !defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--with-mmx
.else
CONFIGURE_ARGS+=	--without-mmx
.endif
.endif

.if defined(WITH_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=	--with-opengl
SNES9X_BIN=	osnes9x
.else
SNES9X_BIN=	snes9x
.endif

.if !defined(WITHOUT_SCREENSHOT)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-screenshot
.else
CONFIGURE_ARGS+=	--without-screenshot
.endif

.if !defined(WITHOUT_JMA)
CONFIGURE_ARGS+=	--with-jma-decomp
.else
CONFIGURE_ARGS+=	--without-jma-decomp
.endif

.if !defined(WITHOUT_NETPLAY)
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in control* changes.txt hardware.txt porting.html faqs.txt \
		snapshots.txt snes9x.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/unix/docs/readme_unix.txt ${DOCSDIR}/README
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/${SNES9X_BIN} ${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

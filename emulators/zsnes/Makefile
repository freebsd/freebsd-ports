PORTNAME=	zsnes
PORTVERSION=	1.51
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ZSNES%20v${PORTVERSION}
DISTNAME=	zsnes${PORTVERSION:S/.//}src

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Intel x86 only Super Nintendo Entertainment System (SNES) Emulator
WWW=		https://www.zsnes.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../docs/license.txt

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	non-portable, for a portable emulator see emulators/snes9x

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake localbase sdl tar:bzip2
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cpucheck
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -std=gnu++03"

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/}/src

PLIST_FILES=	bin/zsnes \
		share/man/man1/zsnes.1.gz

OPTIONS_DEFINE=		AO DEBUGGER JMA OPENGL X11
OPTIONS_DEFAULT=	JMA X11
DEBUGGER_DESC=		ZSNES Debugger
JMA_DESC=		JMA support

AO_LIB_DEPENDS=			libao.so:audio/libao
AO_CONFIGURE_ENABLE=		libao
DEBUGGER_CONFIGURE_ENABLE=	debugger
JMA_CONFIGURE_ENABLE=		jma
OPENGL_CONFIGURE_ENABLE=	opengl
X11_CONFIGURE_WITH=		x

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400000 &&  ${OSVERSION} < 1401000 )
IGNORE= Does not build on FreeBSD 14.0 - zlib is too old
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@CXX@ @CFLAGS@ -o|@CXX@ @CXXFLAGS@ @CPPFLAGS@ -o|g ; s|@CC@ @CFLAGS@ -o|@CC@ @CFLAGS@ @CPPFLAGS@ -o|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -i "" \
		-e 's|-O3||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|size_t argc|int argc|g' \
		${WRKSRC}/parsegen.cpp \
		${WRKSRC}/tools/depbuild.cpp \
		${WRKSRC}/tools/extraext.cpp \
		${WRKSRC}/tools/macroll.cpp \
		${WRKSRC}/tools/minwhite.cpp \
		${WRKSRC}/tools/nreplace.cpp \
		${WRKSRC}/tools/varrep.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zsnes \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/linux/zsnes.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

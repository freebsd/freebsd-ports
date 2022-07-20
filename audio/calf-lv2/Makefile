PORTNAME=	calf
DISTVERSION=	0.90.3.20210427
CATEGORIES=	audio
#MASTER_SITES=	http://calf-studio-gear.org/files/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	lv2>=1.14.0_1:audio/lv2
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		libexpat.so:textproc/expat2

USES=		autoreconf gmake gnome libtool localbase pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lv2 --disable-static

USE_GITHUB=	yes
GH_ACCOUNT=	calf-studio-gear
GH_TAGNAME=	648f05e85287cf08af198bdd9e52baba95b502ec # this revision has clang compilation issues fixed

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS LASH
OPTIONS_DEFAULT=	LASH

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CONFIGURE_WITH=	lash

SSE_CONFIGURE_ENABLE=	sse

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang 
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-finline-limit=80 -finline-functions -finline-functions-called-once
.endif

post-install: # fix absolute symbolic link to be relative
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calf.so
	@${RLN} ${STAGEDIR}${PREFIX}/lib/calf/libcalf.so ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calf.so
	@${RLN} ${STAGEDIR}${PREFIX}/lib/calf/libcalflv2gui.so ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calflv2gui.so

.include <bsd.port.post.mk>

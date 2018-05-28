# Created by: <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	calf
DISTVERSION=	0.90.0
CATEGORIES=	audio
MASTER_SITES=	http://calf-studio-gear.org/files/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio plug-in pack for LV2 and JACK environments

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libexpat.so:textproc/expat2

USES=		autoreconf compiler:c++11-lang gmake libtool localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GNOME=	cairo gtk20
USE_CXXSTD=	c++11
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS LASH LV2
OPTIONS_DEFAULT=	LASH LV2
OPTIONS_SUB=		yes

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CONFIGURE_WITH=	lash
LV2_DESC=		LV2 audio plugin
LV2_BUILD_DEPENDS=	lv2>=1.14.0_1:audio/lv2
LV2_RUN_DEPENDS=	lv2>=1.14.0_1:audio/lv2
LV2_CONFIGURE_WITH=	lv2

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-finline-limit=80 -finline-functions -finline-functions-called-once
.endif

post-install: # fix absolute symbolic link to be relative
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calf.so
	@${RLN} ${STAGEDIR}${PREFIX}/lib/calf/libcalf.so ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calf.so

.include <bsd.port.post.mk>

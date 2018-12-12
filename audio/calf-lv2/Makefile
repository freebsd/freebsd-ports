# Created by: <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	calf
DISTVERSION=	0.90.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://calf-studio-gear.org/files/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	lv2>=1.14.0_1:audio/lv2
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libexpat.so:textproc/expat2

USES=		autoreconf compiler:c++11-lang gmake libtool localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lv2 --disable-static
USE_GNOME=	cairo gtk20
USE_CXXSTD=	c++11
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS LASH
OPTIONS_DEFAULT=	LASH

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CONFIGURE_WITH=	lash

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-finline-limit=80 -finline-functions -finline-functions-called-once
.endif

post-install: # fix absolute symbolic link to be relative
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calf.so
	@${RLN} ${STAGEDIR}${PREFIX}/lib/calf/libcalf.so ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calf.so

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	rlvm
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.14-67
DISTVERSIONSUFFIX=	-g9350209
PORTREVISION=	9
CATEGORIES=	devel games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	RealLive virtual machine clone

LICENSE=	GPLv2 GPLv3 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/utf8.h:devel/utf8cpp
LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libboost_serialization.so:devel/boost-libs \
		libguichan.so:devel/guichan
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USE_GITHUB=	yes
GH_ACCOUNT=	eglaysher

USES=		compiler:c++11-lib pkgconfig scons
USE_GL=		glew glu
USE_GNOME=	gtk20
USE_SDL=	image mixer ttf
EXCLUDE=	GLEW SDL_image SDL_mixer SDL_ttf gmock gtest guichan \
		luabind utf8cpp # leaving only pygame, xclannad, *.cpp
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude vendor/,}
CFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (gtk deps)
MAKE_ARGS=	VERBOSE=1
INSTALLS_ICONS=	yes
PORTDOCS=	AUTHORS.TXT NEWS.TXT README.md STATUS.TXT notes

OPTIONS_DEFINE=	DEBUG DOCS NLS TEST
OPTIONS_DEFAULT=MONA
OPTIONS_MULTI=	JAPANESE_FONT
OPTIONS_MULTI_JAPANESE_FONT=KOCHI MONA SAZANAMI
OPTIONS_SUB=	yes

JAPANESE_FONT_DESC=msgothic.ttc alternatives with verified metrics (unless --font)
KOCHI_DESC=	kochi-gothic-subst.ttf from japanese/font-kochi
KOCHI_RUN_DEPENDS=${LOCALBASE}/share/fonts/TTF/kochi-gothic-subst.ttf:japanese/font-kochi
MONA_DESC=	mona.ttf from japanese/font-mona-ttf
MONA_RUN_DEPENDS=${LOCALBASE}/share/fonts/TTF/mona.ttf:japanese/font-mona-ttf
SAZANAMI_DESC=	sazanami-gothic.ttf from japanese/font-sazanami
SAZANAMI_RUN_DEPENDS=${LOCALBASE}/share/fonts/TTF/sazanami-gothic.ttf:japanese/font-sazanami

DEBUG_MAKE_ARGS_OFF=--release
NLS_USES=	gettext
NLS_EXTRA_PATCHES_OFF=${FILESDIR}/extra-patch-disable-nls
TEST_USES=	lua:51
TEST_BUILD_DEPENDS=googletest>=1.7.0:devel/googletest \
		googlemock>=1.7.0:devel/googlemock \
		luabind>0:devel/luabind
TEST_EXTRA_PATCHES_OFF=${FILESDIR}/extra-patch-disable-test

post-patch:
	@${GREP} -Flr 'utf8cpp/' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-i .bak.utf8cpp -e 's,utf8cpp/,,'
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/src/platforms/gtk/gtk_rlvm_instance.cc
	@${REINPLACE_CMD} -e 's,/usr/share,${LOCALBASE}/share,' \
		-e 's,truetype/ttf-dejavu,dejavu,' \
		-e 's,truetype/[^/"]*/,TTF/,' \
		${WRKSRC}/src/utilities/find_font_file.cc

pre-install-TEST-on:
	(cd ${WRKSRC} && build/${PORTNAME}_unittests)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/src/platforms/gtk/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@(cd ${WRKSRC}/resources && for f in */${PORTNAME}.png; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%/*}x$${f%/*}/apps; \
		${INSTALL_DATA} -v $$f \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%/*}x$${f%/*}/apps; \
	done)

post-install-NLS-on:
	(cd ${WRKSRC}/build/locale && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${PREFIX}/share/locale)

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS:Nnotes}" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		notes ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

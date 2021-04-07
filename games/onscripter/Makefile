PORTNAME=	onscripter
PORTVERSION=	20200722
CATEGORIES=	games
MASTER_SITES=	http://onscripter.osdn.jp/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT?=	Visual novel engine compatible with NScripter

LICENSE=	GPLv2+

LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	sdl_ttf>=2.0.11_6:graphics/sdl_ttf

USES=		gmake jpeg sdl
USE_SDL=	image mixer ttf
MAKEFILE=	Makefile.Linux
ALL_TARGET=	ALL
MAKE_ARGS=	RM="${RM}"
LDFLAGS+=	-Wl,--as-needed # limit jpeg to bin/*conv
PORTDOCS=	*
PLIST_FILES?=	bin/nsaconv \
		bin/nsadec \
		bin/onscripter \
		bin/sarconv \
		bin/sardec

OPTIONS_DEFINE=	DOCS ENGLISH LUA PDA UTF8
OPTIONS_DEFAULT=LUA UTF8
OPTIONS_EXCLUDE?=ENGLISH

ENGLISH_DESC=	Single-byte character mode
ENGLISH_CFLAGS?=-DENABLE_1BYTE_CHAR -DFORCE_1BYTE_CHAR
LUA_USES=	lua
PDA_DESC=	Fit window size to screen on small PDA devices
PDA_CFLAGS?=	-DPDA_AUTOSIZE
UTF8_CFLAGS?=	-DUTF8_CAPTION -DUTF8_FILESYSTEM

post-patch:
	@${REINPLACE_CMD} -e 's/$$(LIBS)/$$(LDFLAGS) &/' \
		${WRKSRC}/Makefile.onscripter

post-patch-LUA-off:
	@${REINPLACE_CMD} '/optional: lua/,/^$$/d' ${WRKSRC}/${MAKEFILE}

.if !target(do-install)
do-install:
.for f in ${PLIST_FILES:T}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

post-install-DOCS-on:
	(cd ${WRKSRC}/www && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR} \
		"! -name *.orig ! -name *.bak")
.endif # do-install

.include <bsd.port.mk>

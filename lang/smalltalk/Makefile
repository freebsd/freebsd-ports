PORTNAME=	smalltalk
PORTVERSION=	3.2.5
PORTREVISION=	19
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU Smalltalk
WWW=		https://smalltalk.gnu.org/

LICENSE=	GPLv2+

BROKEN_powerpc64=	Fails to build: gst-package: did not understand #~
BROKEN_riscv64=		Fails to link: undefined reference to sbrk

BUILD_DEPENDS=	zip:archivers/zip \
		gawk:lang/gawk
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libgdbm.so:databases/gdbm \
		libgmp.so:math/gmp \
		libltdl.so:devel/libltdl

USES=		gl gmake gnome iconv libtool makeinfo pathfix pkgconfig \
		readline shebangfix sqlite tar:xz xorg
USE_GL=		gl glu glut
USE_GNOME=	cairo
USE_XORG=	ice sm x11 xi
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_EMACS=no ac_cv_prog_AWK=gawk
CONFIGURE_ARGS=	--enable-generational-gc=no \
		--enable-gtk=no \
		--localstatedir="${PREFIX}/var" \
		--with-emacs=no
USE_LDCONFIG=	yes
SHEBANG_LANG=	sed
sed_OLD_CMD=	/bin/sed
sed_CMD=	${SED}
SHEBANG_FILES=	packages/vfs/deb packages/vfs/mailfs \
		examples/pepe.sed examples/xml.sed
TEST_TARGET=	check

INFO=		gst gst-base gst-libs
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	PGSQL SDL
OPTIONS_DEFAULT=	PGSQL SDL
OPTIONS_SUB=	yes

PGSQL_USES=	pgsql

SDL_USES=	sdl
SDL_USE=	SDL=image,mixer,sdl,sound,ttf

post-patch:
	@${REINPLACE_CMD} -e 's/ia64-\*-\* /&|amd64-*-* /' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/lrintl (truncl/lroundl (truncl/' \
		${WRKSRC}/libgst/prims.def \
		${WRKSRC}/libgst/prims.inl
	@${REINPLACE_CMD} -e '/^gst_SkippedEntityHandler/,+1s/)/, int)/' \
		${WRKSRC}/packages/xml/expat/expat.c
	@${REINPLACE_CMD} -e '/^ac_include/s/\\$$/#include <wctype.h> \\/' \
		${WRKSRC}/snprintfv/configure

post-build:
	@${SED} -e 's|@bindir@|${PREFIX}/bin|g' \
		${WRKSRC}/gst-mode.el.in > ${WRKSRC}/gst-mode.el

post-install:
	@${LN} -sf gst-load.1 ${STAGEDIR}${PREFIX}/share/man/man1/gst-reload.1
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gst*[^g]
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/smalltalk/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgst.so

.include <bsd.port.mk>

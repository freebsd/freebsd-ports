PORTNAME=	adacurses
DISTVERSION=	20211021
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.invisible-island.net/AdaCurses/
DISTNAME=	AdaCurses-${DISTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Ada95 bindings for ncurses
WWW=		https://invisible-island.net/ncurses/ncurses-Ada95.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README

#BUILD_DEPENDS=	gsed:textproc/gsed
#BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

USES=		ada autoreconf gmake ncurses pkgconfig tar:tgz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ada-include=${PREFIX}/include/adacurses \
		--with-ada-objects=${PREFIX}/lib/adacurses \
		--with-curses-dir=${NCURSESBASE} \
		--libdir=${PREFIX}/lib/adacurses \
		--enable-widec
PORTDOCS=	ada Ada95.html
PLIST_SUB=	atic=adacurses/terminal_interface-curses

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/(INSTALL_PROG)/d' -e 's|@ADAGEN_LDFLAGS@||' \
		${WRKSRC}/gen/Makefile.in
	@${REINPLACE_CMD} -e '/pragma Linker_Options/d' \
		${WRKSRC}/gen/terminal_interface-curses.ads.m4 \
		${WRKSRC}/gen/terminal_interface-curses-menus.ads.m4 \
		${WRKSRC}/gen/terminal_interface-curses-forms.ads.m4 \
		${WRKSRC}/gen/terminal_interface-curses-panels.ads.m4
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ -lmenu -lform -lpanel|' \
		${WRKSRC}/samples/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gen/adacurses-config \
		${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat
	${SED} "s|@PREFIX@|${NCURSESBASE}|g" ${FILESDIR}/adacurses.gpr.in > \
		${STAGEDIR}${PREFIX}/lib/gnat/adacurses.gpr

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} THIS=${PORTNAME} install.html)

.include <bsd.port.mk>

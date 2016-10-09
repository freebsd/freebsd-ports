# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	adacurses
PORTVERSION=	20150808
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/AdaCurses/
DISTNAME=	AdaCurses-${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada95 bindings for ncurses

LICENSE=	MIT

USES=		ada gmake pkgconfig ncurses:port tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ada-include=${PREFIX}/include/adacurses \
		--with-ada-objects=${PREFIX}/lib/adacurses \
		--with-curses-dir=${NCURSESBASE} \
		--libdir=${PREFIX}/lib/adacurses \
		--enable-widec
PORTDOCS=	ada Ada95.html
PLIST_SUB=	atic=adacurses/terminal_interface-curses

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

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

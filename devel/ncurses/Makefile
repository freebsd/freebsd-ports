# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	ncurses
DISTVERSION=	6.2-${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.invisible-island.net/${PORTNAME}/current/ \
		https://invisible-mirror.net/archives/ncurses/current/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Library for terminal-independent, full-screen output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	cannot build: coredump: illegal instruction

USES=		cpe pkgconfig shebangfix tar:tgz terminfo

SNAPSHOT=		20201017
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/misc \
			--disable-home-terminfo \
			--disable-overwrite \
			--disable-root-environ \
			--enable-bsdpad \
			--enable-colorfgbg \
			--enable-getcap \
			--enable-pc-files \
			--enable-rpath \
			--enable-termcap \
			--includedir=${PREFIX}/include/ncurses \
			--program-prefix= \
			--srcdir=../ \
			--with-hashed-db \
			--with-manpage-format=gzip \
			--with-pkg-config-libdir=${PREFIX}/libdata/pkgconfig \
			--with-pkg-config=yes \
			--with-shared \
			--with-termlib \
			--without-manpage-renames

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES MANPAGES PROFILE TRACE
OPTIONS_DEFAULT=	DOCS EXAMPLES MANPAGES

TRACE_DESC=	Add trace() function to all models of ncurses

CONFIGURE_ENV=	gnat_exists="no" cf_cv_ld_searchpath="${LOCALBASE}/lib /usr/lib /lib"

USE_LDCONFIG=	yes
CPE_VENDOR=	gnu
SHEBANG_FILES=	test/tracemunch

WIDEC_WRKSRC=		${WRKSRC}/build.widec
NOWIDEC_WRKSRC=		${WRKSRC}/build.nowidec
WIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/widec
NOWIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/nowidec
EXAMPLES_TARGETS=	NOWIDEC

CONFIGURE_WRKSRC=	${NOWIDEC_WRKSRC}
BUILD_WRKSRC=		${NOWIDEC_WRKSRC}
INSTALL_WRKSRC=		${NOWIDEC_WRKSRC}

PLIST_SUB+=	ABI_VER=6 \
		NOWIDEC_EXAMPLESDIR=${NOWIDEC_EXAMPLESDIR:S,${PREFIX}/,,} \
		REL_VER=${DISTVERSION:S/-${SNAPSHOT}//} \
		WIDEC_EXAMPLESDIR=${WIDEC_EXAMPLESDIR:S,${PREFIX}/,,}

PORTDOCS=	*
PORTEXAMPLES=	*

DOCS=		ANNOUNCE doc/hackguide.doc doc/html/announce.html \
		doc/html/hackguide.html doc/html/index.html \
		doc/html/ncurses-intro.html doc/ncurses-intro.doc INSTALL NEWS \
		README TO-DO
EXAMPLES=	blue.c bs.6 bs.c cardfile.c cardfile.dat ditto.c dots.c \
		filter.c firework.c firstlast.c gdc.6 gdc.c hanoi.c hashtest.c \
		knight.c lrtest.c Makefile ncurses.c newdemo.c railroad.c \
		rain.c README tclock.c test.priv.h testaddch.c testcurs.c \
		testscanw.c view.c worm.c xmas.c
EXAMPLES_CPP=	cursesapp.cc cursesapp.h cursesf.cc cursesf.h cursesm.cc \
		cursesm.h cursesmain.cc cursesp.cc cursesp.h cursesw.cc \
		cursesw.h cursslk.cc cursslk.h demo.cc etip.h internal.h \
		Makefile NEWS PROBLEMS README-first

CONFIGURE_ARGS_WIDEC=	--enable-widec

TRACE_CONFIGURE_ON=		--with-trace
PROFILE_CONFIGURE_WITH=		profile
MANPAGES_CONFIGURE_WITH=	manpages
DEBUG_CONFIGURE_WITH=		debug

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
PLIST_SUB+=	MANPAGES=""
.else
PLIST_SUB+=	MANPAGES="@comment "
.endif

post-extract:
	@${MKDIR} ${WIDEC_WRKSRC}
	@${MKDIR} ${NOWIDEC_WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/include,${PREFIX}/include,g' ${WRKSRC}/misc/ncurses-config.in

post-configure:
	cd ${.CURDIR} && \
	    ${MAKE} ${.MAKEFLAGS} CONFIGURE_WRKSRC=${WIDEC_WRKSRC} \
	    CONFIGURE_ARGS="${CONFIGURE_ARGS} ${CONFIGURE_ARGS_WIDEC}" \
	    do-configure
.for d in test c++
	${CP} -R ${WRKSRC}/${d}/* ${WIDEC_WRKSRC}/${d}/
	${CP} -R ${WRKSRC}/${d}/* ${NOWIDEC_WRKSRC}/${d}/
.endfor

post-build:
	cd ${.CURDIR} && \
	    ${MAKE} ${.MAKEFLAGS} BUILD_WRKSRC=${WIDEC_WRKSRC} do-build

post-install:
	cd ${.CURDIR} && \
	    ${MAKE} ${.MAKEFLAGS} INSTALL_WRKSRC=${WIDEC_WRKSRC} do-install

.for i in ${EXAMPLES_TARGETS}
	@${MKDIR} ${STAGEDIR}${${i}_EXAMPLESDIR}/c++
. for f in ${EXAMPLES}
	${INSTALL_DATA} ${${i}_WRKSRC}/test/${f} ${STAGEDIR}${${i}_EXAMPLESDIR}/
. endfor
	${INSTALL_SCRIPT} ${${i}_WRKSRC}/test/tracemunch ${STAGEDIR}${${i}_EXAMPLESDIR}/
. for f in ${EXAMPLES_CPP}
	${INSTALL_DATA} ${${i}_WRKSRC}/c++/${f} ${STAGEDIR}${${i}_EXAMPLESDIR}/c++/
. endfor
.endfor

	${RM} ${STAGEDIR}${PREFIX}/lib/libncurses.so \
		${STAGEDIR}${PREFIX}/lib/libncursesw.so
	${ECHO} "INPUT(libncurses.so.${PORTVERSION:R} AS_NEEDED(-ltinfo))" > ${STAGEDIR}${PREFIX}/lib/libncurses.so
	${ECHO} "INPUT(libncursesw.so.${PORTVERSION:R} AS_NEEDED(-ltinfow))" > ${STAGEDIR}${PREFIX}/lib/libncursesw.so

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.${DISTVERSION:S/-${SNAPSHOT}//}

	${MV} ${STAGEDIR}${PREFIX}/share/misc/terminfo.db \
		${STAGEDIR}${PREFIX}/share/misc/terminfo.db.default

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>

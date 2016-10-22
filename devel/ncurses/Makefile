# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	ncurses
PORTVERSION=	6.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://invisible-mirror.net/archives/${PORTNAME}/ \
		ftp://invisible-island.net/${PORTNAME}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for terminal-independent, full-screen output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	cannot build: coredump: illegal instruction

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../configure
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/misc --disable-overwrite \
		--enable-termcap --enable-bsdpad --enable-getcap \
		--enable-colorfgbg --disable-home-terminfo \
		--with-pkg-config=yes --enable-pc-files \
		--includedir=${PREFIX}/include/ncurses \
		--with-shared \
		--with-termlib --program-prefix= \
		--enable-rpath --disable-root-environ \
		--with-manpage-format=gzip --srcdir=../ \
		--without-manpage-renames \
		--mandir=${MANPREFIX}/man \
		--with-hashed-db \
		--with-pkg-config-libdir=${PREFIX}/libdata/pkgconfig

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	TRACE DEBUG PROFILE EXAMPLES DOCS
TRACE_DESC=	Add trace() function to all models of ncurses

CONFIGURE_ENV=	gnat_exists="no"

USE_LDCONFIG=	yes
USES=		pkgconfig shebangfix terminfo
SHEBANG_FILES=	test/tracemunch

WIDEC_WRKSRC=	${WRKSRC}/build.widec
NOWIDEC_WRKSRC=	${WRKSRC}/build.nowidec
WIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/widec
NOWIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/nowidec
EXAMPLES_TARGETS=	NOWIDEC

CONFIGURE_WRKSRC=	${NOWIDEC_WRKSRC}
BUILD_WRKSRC=	${NOWIDEC_WRKSRC}
INSTALL_WRKSRC=	${NOWIDEC_WRKSRC}

PLIST_SUB+=	ABI_VER=${PORTVERSION:R} \
		REL_VER=${PORTVERSION} \
		WIDEC_EXAMPLESDIR=${WIDEC_EXAMPLESDIR:S,${PREFIX}/,,} \
		NOWIDEC_EXAMPLESDIR=${NOWIDEC_EXAMPLESDIR:S,${PREFIX}/,,}

PORTDOCS=	*
PORTEXAMPLES=	*

DOCS=	ANNOUNCE INSTALL NEWS README TO-DO doc/html/announce.html \
	doc/hackguide.doc doc/html/hackguide.html \
	doc/html/index.html doc/ncurses-intro.doc \
	doc/html/ncurses-intro.html
EXAMPLES=	Makefile README blue.c bs.6 bs.c cardfile.c cardfile.dat \
		ditto.c dots.c filter.c firework.c firstlast.c gdc.6 \
		gdc.c hanoi.c hashtest.c knight.c lrtest.c ncurses.c \
		newdemo.c railroad.c rain.c tclock.c test.priv.h \
		testaddch.c testcurs.c testscanw.c view.c worm.c \
		xmas.c
EXAMPLES_CPP=	Makefile NEWS PROBLEMS README-first cursesapp.cc \
		cursesapp.h cursesf.cc cursesf.h cursesm.cc cursesm.h \
		cursesmain.cc cursesp.cc cursesp.h cursesw.cc \
		cursesw.h cursslk.cc cursslk.h demo.cc etip.h \
		internal.h

CONFIGURE_ARGS_WIDEC=--enable-widec

TRACE_CONFIGURE_ON=	--with-trace
PROFILE_CONFIGURE_WITH=	profile
DEBUG_CONFIGURE_WITH=	debug

OPTIONS_SUB=yes

.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${WIDEC_WRKSRC}
	@${MKDIR} ${NOWIDEC_WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,$$(INSTALL_PROG) ncurses-config,@INSTALL_SCRIPT@ ncurses-config,' ${WRKSRC}/misc/Makefile.in
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

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.${PORTVERSION}

	${MV} ${STAGEDIR}${PREFIX}/share/misc/terminfo.db \
		${STAGEDIR}${PREFIX}/share/misc/terminfo.db.default

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:	ncurses
# Date created:				23 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	ncurses
PORTVERSION=	${RELEASE}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Library for terminal-independent, full-screen output

CONFLICTS=	ncurses-devel-*

RELEASE=	5.8

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../configure
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/misc --disable-overwrite \
		--enable-termcap --enable-bsdpad --enable-getcap \
		--enable-colorfgbg --disable-home-terminfo \
		--with-pkg-config=no \
		--includedir=${PREFIX}/include/ncurses \
		--with-shared \
		--without-curses-h --with-termlib --program-prefix= \
		--enable-rpath --disable-root-environ \
		--with-manpage-format=gzip --srcdir=../
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	EXTCOLORS "Enable 256-color support (only for ncursesw)" off

CONFIGURE_ENV=	gnat_exists="no"

USE_LDCONFIG=	yes

WIDEC_WRKSRC=	${WRKSRC}/build.widec
NOWIDEC_WRKSRC=	${WRKSRC}/build.nowidec
WIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/widec
NOWIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/nowidec
EXAMPLES_TARGETS=	NOWIDEC

CONFIGURE_WRKSRC=	${NOWIDEC_WRKSRC}
BUILD_WRKSRC=	${NOWIDEC_WRKSRC}
INSTALL_WRKSRC=	${NOWIDEC_WRKSRC}

NCURSES_ABI_VER=	5
NCURSES_REL_VER=	${RELEASE}
NCURSESW_ABI_VER=	${NCURSES_ABI_VER}
NCURSESW_REL_VER=	${NCURSES_REL_VER}

PLIST_SUB+=	ABI_VER=${NCURSES_ABI_VER} \
		REL_VER=${NCURSES_REL_VER} \
		ABI_VER_WIDEC=${NCURSESW_ABI_VER} \
		REL_VER_WIDEC=${NCURSESW_REL_VER} \
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

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.man"

CONFIGURE_ARGS_WIDEC=--enable-widec
.if defined(WITH_EXTCOLORS)
CONFIGURE_ARGS_WIDEC+=--enable-ext-colors
NCURSESW_ABI_VER=	6
NCURSESW_REL_VER=	6.0
.endif

# needed by devel/py-ncurses port
.if defined(WITH_TRACE)
CONFIGURE_ARGS+=	--with-trace
.endif

.if !defined(WITHOUT_PROFILE) && !defined(NO_PROFILE) && !defined(NOPROFILE)
CONFIGURE_ARGS+=--with-profile
PLIST_SUB+=	PROFILE=""
.else
CONFIGURE_ARGS+=--without-profile
PLIST_SUB+=	PROFILE="@comment "
.endif

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--without-debug
PLIST_SUB+=	DEBUG="@comment "
.else
CONFIGURE_ARGS+=--with-debug
PLIST_SUB+=	DEBUG=""
.endif

.if !defined(WITHOUT_TERMINFO)
CONFIGURE_ARGS+=--with-hashed-db
PLIST_SUB+=	TERMINFO=""
.else # termcap only, easier for updating ncurses in base
CONFIGURE_ARGS+=--disable-database
PLIST_SUB+=	TERMINFO="@comment "
.endif

.if !defined(WITHOUT_WIDEC)
PLIST_SUB+=	WIDEC=""
EXAMPLES_TARGETS+=	WIDEC
.else
PLIST_SUB+=	WIDEC="@comment "
.endif

post-extract:
	@${MKDIR} ${WIDEC_WRKSRC}
	@${MKDIR} ${NOWIDEC_WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,$$(INSTALL_PROG) ncurses-config,@INSTALL_SCRIPT@ ncurses-config,' ${WRKSRC}/misc/Makefile.in

post-configure:
.if !defined(WITHOUT_WIDEC)
	cd ${.CURDIR} && \
	    ${MAKE} ${.MAKEFLAGS} CONFIGURE_WRKSRC=${WIDEC_WRKSRC} \
	    CONFIGURE_ARGS="${CONFIGURE_ARGS} ${CONFIGURE_ARGS_WIDEC}" \
	    do-configure
.endif
.for d in test c++
.if !defined(WITHOUT_WIDEC)
	${CP} ${WRKSRC}/${d}/* ${WIDEC_WRKSRC}/${d}/
.endif
	${CP} ${WRKSRC}/${d}/* ${NOWIDEC_WRKSRC}/${d}/
.endfor

post-build:
.if !defined(WITHOUT_WIDEC)
	cd ${.CURDIR} && \
	    ${MAKE} ${.MAKEFLAGS} BUILD_WRKSRC=${WIDEC_WRKSRC} do-build
.endif

post-install:
.if !defined(WITHOUT_WIDEC)
	cd ${.CURDIR} && \
	    ${MAKE} ${.MAKEFLAGS} INSTALL_WRKSRC=${WIDEC_WRKSRC} do-install
.endif

.if !defined(NOPORTEXAMPLES)
. for i in ${EXAMPLES_TARGETS}
	${MKDIR} ${${i}_EXAMPLESDIR}/c++
.  for f in ${EXAMPLES}
	${INSTALL_DATA} ${${i}_WRKSRC}/test/${f} ${${i}_EXAMPLESDIR}/
.  endfor
	${INSTALL_SCRIPT} ${${i}_WRKSRC}/test/tracemunch ${${i}_EXAMPLESDIR}/
.  for f in ${EXAMPLES_CPP}
	${INSTALL_DATA} ${${i}_WRKSRC}/c++/${f} ${${i}_EXAMPLESDIR}/c++/
.  endfor
. endfor
.endif

.if !defined(WITHOUT_TERMINFO)
	${FIND} ${PREFIX}/share/misc -name "*.terminfo" -print0	|	\
		${XARGS} -0 ${PREFIX}/bin/tic
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
. endfor
.endif

.include <bsd.port.post.mk>

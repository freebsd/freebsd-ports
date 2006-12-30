# New ports collection makefile for:	ncurses
# Date created:				23 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	ncurses
PORTVERSION=	5.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Library for terminal-independent, full-screen output

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../configure
CONFIGURE_ARGS=	--datadir=${TARGETDIR}/share/misc --disable-overwrite \
		--enable-termcap --disable-database --enable-getcap \
		--enable-colorfgbg --enable-bsdpad --disable-home-terminfo \
		--includedir=${TARGETDIR}/include/ncurses \
		--with-profile --with-shared --without-debug \
		--without-curses-h --with-termlib --program-prefix= \
		--enable-safe-sprintf --disable-root-environ \
		--with-manpage-format=gzip --srcdir=../

# needed by devel/py-ncurses port
.if defined(WITH_TRACE)
CONFIGURE_ARGS+=	--with-trace
.endif

LDFLAGS+=	-rpath ${TARGETDIR}/lib

CONFIGURE_ENV=	gnat_exists="no" \
		ac_cv_path_LDCONFIG="${LDCONFIG} -m ${TARGETDIR}/lib" \
		LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	yes
NO_FILTER_SHLIBS=yes

WIDEC_WRKSRC=	${WRKSRC}/build.widec
NOWIDEC_WRKSRC=	${WRKSRC}/build.nowidec
WIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/widec
NOWIDEC_EXAMPLESDIR=	${EXAMPLESDIR}/nowidec
EXAMPLES_TARGETS=	NOWIDEC

CONFIGURE_WRKSRC=	${NOWIDEC_WRKSRC}
BUILD_WRKSRC=	${NOWIDEC_WRKSRC}
INSTALL_WRKSRC=	${NOWIDEC_WRKSRC}

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		WIDEC_EXAMPLESDIR=${WIDEC_EXAMPLESDIR:S,${TARGETDIR}/,,} \
		NOWIDEC_EXAMPLESDIR=${NOWIDEC_EXAMPLESDIR:S,${TARGETDIR}/,,}

MANCOMPRESSED=	yes
MAN1=	captoinfo.1m clear.1 infocmp.1m infotocap.1m reset.1 tack.1 \
	tic.1m toe.1m tput.1 tset.1
MAN5=	term.5 terminfo.5
MAN7=	term.7

PORTDOCS=	*

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

MAN3!=	${CAT} ${FILESDIR}/man3

.if ${OSVERSION} >= 400000
MANUAL_PACKAGE_BUILD=	conflicts with system ncurses
.endif

.if ${OSVERSION} < 503000
WITHOUT_WIDEC=	yes
PLIST_SUB+=	WIDEC="@comment "
.else
PLIST_SUB+=	WIDEC=""
EXAMPLES_TARGETS+=	WIDEC
.endif

post-extract:
	@${MKDIR} ${WIDEC_WRKSRC}
	@${MKDIR} ${NOWIDEC_WRKSRC}

post-configure:
.if !defined(WITHOUT_WIDEC)
	${MAKE} CONFIGURE_WRKSRC=${WIDEC_WRKSRC} \
	    CONFIGURE_ARGS="${CONFIGURE_ARGS} --enable-widec" \
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
	${MAKE} BUILD_WRKSRC=${WIDEC_WRKSRC} do-build
.endif

post-install:
.if !defined(WITHOUT_WIDEC)
	${MAKE} INSTALL_WRKSRC=${WIDEC_WRKSRC} do-install
.endif

	${INSTALL_DATA} ${WRKSRC}/misc/terminfo.src \
		${TARGETDIR}/share/misc/terminfo

.for i in ${EXAMPLES_TARGETS}
	${MKDIR} ${${i}_EXAMPLESDIR}/c++
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${${i}_WRKSRC}/test/${f} ${${i}_EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${${i}_WRKSRC}/test/tracemunch ${${i}_EXAMPLESDIR}
.for f in ${EXAMPLES_CPP}
	${INSTALL_DATA} ${${i}_WRKSRC}/c++/${f} ${${i}_EXAMPLESDIR}/c++
.endfor
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>

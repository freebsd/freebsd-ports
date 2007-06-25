# New ports collection makefile for:	ncurses-devel
# Date created:				Jan 28 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ncurses
PORTVERSION=	${RELEASE}.${PATCHDATE}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${RELEASE}
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	ftp://invisible-island.net/ncurses/${RELEASE}/ \
		${MASTER_SITE_LOCAL:S/$/:local/}
PATCH_SITE_SUBDIR=	rafan/ncurses/:local

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Library for terminal-independent, full-screen output (development version)

CONFLICTS=	ncurses-[0-9]*

PATCHES=	20061223 20061230 20070106 20070113 20070120 20070127 20070128 \
		20070203 20070210 20070217 20070224 20070303 20070310 20070311 \
		20070317 20070324 20070331 20070407 20070414 20070421 20070428 \
		20070505 20070512 20070526 20070602 20070609 20070612 20070623

RELEASE=	5.6

.for i in ${PATCHES}
PATCHFILES+=	${PORTNAME}-${RELEASE}-${i}.patch.gz:DEFAULT,local
PATCHDATE=	${i}
.endfor

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../configure
CONFIGURE_ARGS=	--datadir=${TARGETDIR}/share/misc --disable-overwrite \
		--enable-termcap --enable-bsdpad --enable-getcap \
		--enable-colorfgbg --disable-home-terminfo \
		--includedir=${TARGETDIR}/include/ncurses \
		--with-shared \
		--without-curses-h --with-termlib --program-prefix= \
		--enable-rpath --disable-root-environ \
		--with-manpage-format=gzip --srcdir=../

# needed by devel/py-ncurses port
.if defined(WITH_TRACE)
CONFIGURE_ARGS+=	--with-trace
.endif

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

PLIST_SUB+=	PORTVERSION=${RELEASE} \
		WIDEC_EXAMPLESDIR=${WIDEC_EXAMPLESDIR:S,${TARGETDIR}/,,} \
		NOWIDEC_EXAMPLESDIR=${NOWIDEC_EXAMPLESDIR:S,${TARGETDIR}/,,}

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

.if ${OSVERSION} < 503000
WITHOUT_WIDEC=	yes
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
	${MAKE} CONFIGURE_WRKSRC=${WIDEC_WRKSRC} \
	    CONFIGURE_ARGS="${CONFIGURE_ARGS} --enable-widec" \
	    do-configure
.endif
.for d in test c++
. if !defined(WITHOUT_WIDEC)
	${CP} ${WRKSRC}/${d}/* ${WIDEC_WRKSRC}/${d}/
. endif
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

.if !defined(NOPORTEXAMPLES)
. for i in ${EXAMPLES_TARGETS}
	${MKDIR} ${${i}_EXAMPLESDIR}/c++
.  for f in ${EXAMPLES}
	${INSTALL_DATA} ${${i}_WRKSRC}/test/${f} ${${i}_EXAMPLESDIR}
.  endfor
	${INSTALL_SCRIPT} ${${i}_WRKSRC}/test/tracemunch ${${i}_EXAMPLESDIR}
.  for f in ${EXAMPLES_CPP}
	${INSTALL_DATA} ${${i}_WRKSRC}/c++/${f} ${${i}_EXAMPLESDIR}/c++
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
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:   doxygen
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.2.18
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	kde@freebsd.org

ALL_TARGET=	all

.if !defined(NOPORTDOCS)
ALL_TARGET+=	docs
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.else
.undef HAVE_LATEX
.endif # !defined(NOPORTDOCS)

.if defined(HAVE_LATEX)
ALL_TARGET+=	pdf
PLIST_SUB+=	HAVE_LATEX=""
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
MAKE_ARGS+=	HAVE_LATEX=yes
.else # !defined(HAVE_LATEX)
PLIST_SUB+=	HAVE_LATEX="@comment "
.endif # !defined(HAVE_LATEX)

.if defined(WITH_QT2)
BROKEN=	"QT2 support has been removed"
.else # not QT2
USE_QT_VER=	3
QT_INC=		${X11BASE}/include
QTNAME=		qt-mt
QT_OPENGL=
THREADLIBS=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
.endif # not QT2

# Need this in env for build
QTDIR?=		${X11BASE}
CONFIGURE_ENV+=	QTDIR="${QTDIR}"

USE_PERL5=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguments
CONFIGURE_ARGS+=--prefix ${PREFIX} --perl ${PERL} --make ${GMAKE} \
		--with-doxywizard --install ${INSTALL}

.if !defined(NOPORTDOCS) && !defined(HAVE_LATEX)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "================================================="
	@${ECHO_MSG} "If you want DVI, Postscript, and PDF documentation"
	@${ECHO_MSG} "in addition to the HTML documentation,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make HAVE_LATEX=yes\""
	@${ECHO_MSG} "================================================="
	@${ECHO_MSG}
.endif # !defined(NOPORTDOCS) && !defined(HAVE_LATEX)

pre-configure:
	@${PERL} -pi -e "s:gcc:${CC}:g;		\
		s:g\+\+:${CXX}:g;		\
		s:%%LIBQT%%:-l${QTNAME}:g;	\
		s:%%MOC%%:${MOC}:g;		\
		s:%%QT_INC%%:${QT_INC}:g;	\
		s:%%QT_LIB%%:${X11BASE}/lib:g;	\
		s:%%QT_OPENGL%%:${QT_OPENGL}:g;	\
		s:%%THREADLIBS%%:${THREADLIBS}:g;\
		s:%%CFLAGS%%:${CFLAGS}:g;	\
		s:%%CXXFLAGS%%:${CXXFLAGS}:g"	\
	    ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf

post-patch:
	@${PERL} -pi.fbsd -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/libpng/pngconf.h \
		${WRKSRC}/libpng/zutil.h ${WRKSRC}/src/pngenc.cpp

post-build:
	cd ${BUILD_WRKSRC}/examples; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxytag ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxysearch ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxywizard ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/doxygen/html
	${TAR} -C ${WRKSRC} --exclude '*/_*' -cf - html \
		| ${TAR} -C ${PREFIX}/share/doc/doxygen --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude '*/Makefile*' --exclude '*.dot' \
		-cf - examples \
	    | ${TAR} -C ${PREFIX}/share/doc/doxygen --unlink -xf -
.ifdef HAVE_LATEX
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.dvi \
			${WRKSRC}/latex/doxygen_manual.pdf \
			${WRKSRC}/latex/doxygen_manual.ps \
			${WRKSRC}/latex/archoverview.eps \
			${WRKSRC}/latex/doxygen_logo.eps \
			${PREFIX}/share/doc/doxygen
.endif # HAVE_LATEXT
.endif # ! NOPORTDOCS

.include <bsd.port.mk>

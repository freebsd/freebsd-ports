# New ports collection makefile for:   doxygen
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.2.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	bsdport@ddm.wox.org

.ifndef NOPORTDOCS
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
.ifdef HAVE_LATEX
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX \
		dvipdfm:${PORTSDIR}/print/dvipdfm
.endif
.endif

USE_QT_VER=	2
USE_PERL5=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguments
CONFIGURE_ARGS+=--prefix ${PREFIX} --perl ${PERL} --make ${GMAKE} \
		--with-doxywizard

# As of 1.2.13 the configure script bogusly checks for GNU options
# in install so we need to override it's sillyness here.
CONFIGURE_ARGS+=--install ${INSTALL}

# XXX bsd.kde.mk fails to set QTDIR for QT_VER 2
QTDIR?=		${X11BASE}
CONFIGURE_ENV+=	QTDIR="${QTDIR}"

.ifndef NOPORTDOCS
ALL_TARGET=	all docs
.ifdef HAVE_LATEX
ALL_TARGET+=	ps
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX \
		dvipdfm:${PORTSDIR}/print/dvipdfm
PLIST_SUB+=	HAVE_LATEX=""
.else
PLIST_SUB+=	HAVE_LATEX="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want DVI, Postscript, and PDF documentation"
	@${ECHO_MSG} "in addition to the HTML documentation,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make HAVE_LATEX=yes\""
	@${ECHO_MSG}
.endif
.endif

pre-configure:
	@${PERL} -pi -e "s:gcc:${CC}:g ; s:g\+\+:${CXX}:g ; \
		s:%%LIBQT%%:-l${QTNAME}:g ; \
		s:%%MOC%%:${MOC}:g ; \
		s:%%QT_INC%%:${X11BASE}/include/qt2:g ; \
		s:%%QT_LIB%%:${X11BASE}/lib:g ; \
		s:%%CFLAGS%%:${CFLAGS}:g ; \
		s:%%CXXFLAGS%%:${CXXFLAGS}:g" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxytag ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxysearch ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxywizard ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/doxygen/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/doc/doxygen/html
	${TAR} -C ${WRKSRC} --exclude '*/Makefile*' -cf - examples | \
		${TAR} -C ${PREFIX}/share/doc/doxygen --unlink -xf -
.ifdef HAVE_LATEX
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.dvi \
			${WRKSRC}/latex/doxygen_manual.pdf \
			${WRKSRC}/latex/doxygen_manual.ps \
			${WRKSRC}/latex/archoverview.eps \
			${WRKSRC}/latex/doxygen_logo.eps \
			${PREFIX}/share/doc/doxygen
.endif
.endif

.include <bsd.port.mk>

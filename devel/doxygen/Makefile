# New ports collection makefile for:   doxygen
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	bsdport@ddm.wox.org

.ifndef NOPORTDOCS
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
.endif

USE_QT_VER=	2
USE_PERL5=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguements
CONFIGURE_ARGS+=--prefix ${PREFIX} --perl ${PERL} --make ${GMAKE} \
		--with-doxywizard

.ifndef NOPORTDOCS
ALL_TARGET=	all docs
.ifdef HAVE_LATEX
ALL_TARGET+=	ps
PLIST_SUB+=	HAVE_LATEX=""
.else
PLIST_SUB+=	HAVE_LATEX="@comment "
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
			${PREFIX}/share/doc/doxygen
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.ps \
			${PREFIX}/share/doc/doxygen
.endif
.endif

.include <bsd.port.mk>

# New ports collection makefile for:   doxygen
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.2.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	joep@di.nl

USE_QT_VER=	1
USE_PERL5=	yes
MAKE_ENV+=	QTDIR="${X11BASE}" PCFLAGS="${CFLAGS}" PCXXFLAGS="${CXXFLAGS}"
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--prefix ${PREFIX} --perl ${PERL5} --make ${GMAKE}
CONFIGURE_ENV+=	QTDIR=${X11BASE}
ALL_TARGET=	all docs
.ifdef HAVE_LATEX
ALL_TARGET+=	ps
PLIST_SUB+=	HAVE_LATEX=""
.else
PLIST_SUB+=	HAVE_LATEX="@comment "
.endif

pre-configure:
	@${PERL} -pi -e "s:gcc:${CC}:g ; s:g\+\+:${CXX}:g ; \
		s:%%CFLAGS%%:${CFLAGS}:g ; \
		s:%%CXXFLAGS%%:${CXXFLAGS}:g" ${WRKSRC}/tmake/lib/freebsd-g++/tmake.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxytag ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxysearch ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/doxygen/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/doc/doxygen/html
.ifdef HAVE_LATEX
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.dvi \
			${PREFIX}/share/doc/doxygen
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.ps \
			${PREFIX}/share/doc/doxygen
.endif
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libdjvu++
PORTVERSION=	2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.djvu.com/open/

MAINTAINER=	mi@aldan.algebra.com

INSTALLS_SHLIBS=	yes
IS_INTERACTIVE=	yes
USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=${CXX}
CONFIGURE_ARGS=	--with-cxxflag="${CXXFLAGS}"
MAKE_ARGS=	OPT=""

post-extract:
	${SH} ${WRKSRC}/RunMe

do-install:
.for prog in djvuinfo c44 d44 djvutopnm djvumake djvuextract ppmcoco bzz
	${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
.for lib in libdjvu++.a libdjvu++.so.2
	${INSTALL_DATA} ${WRKSRC}/${lib} ${PREFIX}/lib
.endfor
	${LN} -sf libdjvu++.so.2 ${PREFIX}/lib/libdjvu++.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/djvu
	${INSTALL_DATA} ${WRKSRC}/@Doc/* ${PREFIX}/share/doc/djvu
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libdjvu++
PORTVERSION=	2.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://djvu.research.att.com/open/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	AT&T's DjVu: The Technology for Scanned Documents on the Web

INSTALLS_SHLIB=	yes
IS_INTERACTIVE=	some think, the AT&T license needs to be acked by the user
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=${CXX}
CONFIGURE_ARGS=	--with-cxxflag="${CXXFLAGS}"
MAKE_ARGS=	OPT="" -j 2

pre-patch:
	${SH} ${WRKSRC}/RunMe

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} c44 d44 djvutopnm djvumake \
		djvuextract ppmcoco bzz djvuinfo ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libdjvu++.a ${WRKSRC}/libdjvu++.so.2* \
		 ${PREFIX}/lib
	${LN} -sf libdjvu++.so.2* ${PREFIX}/lib/libdjvu++.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/djvu
	${INSTALL_DATA} ${WRKSRC}/@Doc/* ${PREFIX}/share/doc/djvu

PLIST_SUB+=	DOC=''
.else
PLIST_SUB+=	DOC='@comment '
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	korelib
# Date created:				10 May 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	korelib
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://host33.ipowerweb.com/~smga3000/thekompany/Korelib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform C++ library for developing modular applications

USE_KDELIBS_VER=3
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

pre-configure:
	${REINPLACE_CMD} -e "s@-g -O2@${CXXFLAGS}@g; s@-O2@${CFLAGS}@g" \
		${WRKSRC}/configure ${WRKSRC}/*/Makefile.in ${WRKSRC}/*/*/Makefile.in
	${REINPLACE_CMD} -e "s@autoheader@autoheader213@" ${WRKSRC}/aclocal.m4

post-install:
	${RM} -f ${PREFIX}/lib/libkore.la

.include <bsd.port.mk>

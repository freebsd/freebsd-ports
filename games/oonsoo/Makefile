# New ports collection makefile for:	oonsoo
# Date created:		23rd June, 1997
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

PORTNAME=	oonsoo
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www4.ncsu.edu/~bwmott/www/oonsoo/distributions/
MASTER_SITE_SUBDIR=	games/solitaires
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A solitaire card game for X

PLIST_FILES=	bin/oonsoo
USE_XLIB=	yes
MAKEFILE=	Makefile.Linux
MAKE_ARGS=	CC="${CXX}" CPPFLAGS="${CXXFLAGS} -ansi"	\
		SYS_INCLUDE="-I${X11BASE}/include"		\
		SYS_LIBS="-L${X11BASE}/lib -lX11"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/oonsoo ${PREFIX}/bin

.include <bsd.port.mk>

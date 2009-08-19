# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	tinyq
# Date created:		2003-01-25
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	tinyq
PORTVERSION=	3.0.6
PORTREVISION=	2
PORTEPOCH=	0
CATEGORIES=	devel kde
MASTER_SITES=	http://www.uwyn.com/download/tinyq/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A stripped down version of Qt 3 for use as a utility library

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-thread -stl -prefix ${PREFIX}/tinyq
CONFIGURE_ENV+=	QTDIR="${WRKSRC}"
MAKE_ENV+=	QTDIR="${WRKSRC}"
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CXXFLAGS}|' \
		-e 's|gcc|${CC}|' \
		-e 's|g++|${CXX}|' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${LOCALBASE}|' \
		-e 's|release|release thread|' \
		-e 's|-pthread -D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e 's|-pthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf

.include <bsd.port.mk>

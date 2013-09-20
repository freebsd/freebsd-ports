# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	tinyq
PORTVERSION=	3.0.6
PORTREVISION=	2
PORTEPOCH=	0
CATEGORIES=	devel kde
MASTER_SITES=	http://www.uwyn.com/download/tinyq/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A stripped down version of Qt 3 for use as a utility library

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-thread -stl -prefix ${PREFIX}/tinyq
CONFIGURE_ENV+=	QTDIR="${WRKSRC}"
MAKE_ENV+=	QTDIR="${WRKSRC}"
REINPLACE_ARGS=	-i ''

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CXXFLAGS}|' \
		-e 's|gcc|${CC}|' \
		-e 's|g++|${CXX}|' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${LOCALBASE}|' \
		-e 's|release|release thread|' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf

.include <bsd.port.mk>

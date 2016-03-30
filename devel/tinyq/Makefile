# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	tinyq
PORTVERSION=	3.0.6
PORTREVISION=	4
CATEGORIES=	devel kde
MASTER_SITES=	http://www.uwyn.com/download/tinyq/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stripped down version of Qt 3 for use as a utility library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

USES=		gmake tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-thread -stl -prefix ${PREFIX}/tinyq -docdir ${DOCSDIR}
CONFIGURE_ENV=	QTDIR="${WRKSRC}"
MAKE_ENV=	QTDIR="${WRKSRC}" INSTALL_ROOT="${STAGEDIR}"
REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CXXFLAGS}|' \
		-e 's|gcc|${CC}|' \
		-e 's|g++|${CXX}|' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${LOCALBASE}|' \
		-e 's|release|release thread|' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/tinyq/bin/qmake
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/tinyq/lib/libtinyq-mt.so

.include <bsd.port.mk>

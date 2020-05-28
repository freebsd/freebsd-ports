# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	openzwave
PORTVERSION=	1.6.${VERSION_REV}
CATEGORIES=	comms
PKGNAMESUFFIX=	-devel

MAINTAINER=	kiwi@oav.net
COMMENT=	Open-source interface to Z-Wave networks

LICENSE=	LGPL20

USES=		compiler:c++11-lang gmake tar:bz2 iconv pkgconfig

# Manually update this when makefile is updated
# echo $(git describe --long --tags --dirty 2>/dev/null | sed s/^v//) | awk '{split($$0,a,"-"); print a[2]}'
VERSION_REV=	1061

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OpenZWave
GH_PROJECT=	open-zwave
GH_TAGNAME=	14f2ba74
MAKE_ARGS=	VERSION_REV=${VERSION_REV} LIBDIR=${WRKSRC} docdir=${DOCSDIR} CXX=${CXX}

OPTIONS_DEFINE=	DOXYGEN DOCS
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

DOXYGEN_DESCR=	Build docs (requires doxygen + graphviz)
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen dot:${PORTSDIR}/graphics/graphviz
DOXYGEN_PORTDOCS=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libopenzwave.so.1.6
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/MinOZW

post-install-DOXYGEN-on:
	${RM} ${STAGEDIR}${DOCSDIR}/Doxyfile.in

.include <bsd.port.mk>

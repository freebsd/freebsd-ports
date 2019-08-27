# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	openzwave
PORTVERSION=	1.6.${VERSION_REV}
CATEGORIES=	comms
PKGNAMESUFFIX=	-devel

MAINTAINER=	kiwi@oav.net
COMMENT=	Open-zwave - An open-source interface to Z-Wave networks

LICENSE=	LGPL20

USES=		gmake tar:bz2 iconv pkgconfig

# Manually update this when makefile is updated
# echo $(git describe --long --tags --dirty 2>/dev/null | sed s/^v//) | awk '{split($$0,a,"-"); print a[2]}'
VERSION_REV=	897

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OpenZWave
GH_PROJECT=	open-zwave
GH_TAGNAME=	1e2d123c

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

DOXYGEN_DESCR=	Build docs (requires doxygen + graphviz)
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen dot:${PORTSDIR}/graphics/graphviz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=api/* default.htm general/* images+css/*
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libopenzwave.so.1.6
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/MinOZW
.if ! ${PORT_OPTIONS:MDOXYGEN}
# If doxygen was installed in env, it was built anyway..
# Or even if it isnt, some files are copied here.
	${RM} -rf ${STAGEDIR}${DOCSDIR}
.else
	${RM} ${STAGEDIR}${DOCSDIR}/Doxyfile.in
.endif

MAKE_ARGS=VERSION_REV=${VERSION_REV} LIBDIR=${WRKSRC} docdir=${DOCSDIR}

.include <bsd.port.mk>

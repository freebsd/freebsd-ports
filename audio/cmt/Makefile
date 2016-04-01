# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmt
PORTVERSION=	1.16
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	${PORTNAME}_src_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Computer Music Toolkit - a collection of LADSPA plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}/src

USES=		gmake tar:tgz
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -fPIC -I${LOCALBASE}/include"
ALL_TARGET=	targets

PLIST_FILES=	lib/ladspa/cmt.so

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/plugins/cmt.so ${STAGEDIR}${PREFIX}/lib/ladspa/

.include <bsd.port.mk>

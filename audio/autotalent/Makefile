# Created by: Rich Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	autotalent
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	http://tombaran.info/
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time pitch correction plugin for LADSPA

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake

MAKE_ARGS=	CXX="${CXX}" CC="${CC}" CPP="${CPP}" \
		CXXFLAGS="${CXXFLAGS} -fPIC -I${LOCALBASE}/include"

ALL_TARGET=	targets

PLIST_FILES=	lib/ladspa/autotalent.so

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"
	${REINPLACE_CMD} -e "s,-O3 -Wall -fomit-frame-pointer -fstrength-reduce -funroll-loops -ffast-math,${CFLAGS}," ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/autotalent.so ${STAGEDIR}${PREFIX}/lib/ladspa

.include <bsd.port.mk>

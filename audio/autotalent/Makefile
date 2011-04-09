# New ports collection Makefile for:   autotalent
# Date created:         03/24/11
# Whom:                 Rich Neese <r.neese@gmail.com>
#
# $FreeBSD$

PORTNAME=	autotalent
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	http://web.mit.edu/tbaran/www/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	r.neese@gmail.com
COMMENT=	A real-time pitch correction plugin for ladspa

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GMAKE=	yes

MAKE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -fPIC -I${LOCALBASE}/include"

ALL_TARGET=	targets

PLIST_FILES=	lib/ladspa/autotalent.so

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"
	${REINPLACE_CMD} -e "s,-O3 -Wall -fomit-frame-pointer -fstrength-reduce -funroll-loops -ffast-math,${CFLAGS}," ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/autotalent.so ${PREFIX}/lib/ladspa/

.include <bsd.port.mk>

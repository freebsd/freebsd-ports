PORTNAME=	ladspa
PORTVERSION=	1.17
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	ladspa_sdk_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux Audio Developer's Simple Plugin API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/doc/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		gmake tar:tgz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/ladspa_sdk_${PORTVERSION}
PROGRAM_FILES=	analyseplugin applyplugin listplugins
PLUGIN_FILES=	amp.so delay.so filter.so noise.so sine.so
PLUGIN_DIR?=	${STAGEDIR}${PREFIX}/lib/ladspa/
ALL_TARGET=	targets
BUILD_WRKSRC=	${WRKSRC}/src

post-patch:
	${REINPLACE_CMD} -e 's,-ldl,,; s,-O3,${CFLAGS},; s,-Werror ,,; \
		s,^CC,#CC,;s,^CPP,#CPP,;s,CPP,CXX,; s,^CXXFLAGS.*=,CXXFLAGS+=,; \
		s,lsndfile,lsndfile -L${LOCALBASE}/lib,;s,I\.,I. -I${LOCALBASE}/include,' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/ladspa.h ${STAGEDIR}${PREFIX}/include
.for file in ${PROGRAM_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${PLUGIN_DIR}
.for file in ${PLUGIN_FILES}
	${INSTALL_LIB} ${WRKSRC}/plugins/${file} ${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>

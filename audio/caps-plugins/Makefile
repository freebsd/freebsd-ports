PORTNAME=	caps-plugins
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://quitte.de/dsp/
DISTNAME=	caps_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	The C* LADSPA Audio Plugin Suite
WWW=		http://quitte.de/dsp/caps.html

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake
USE_CXXSTD=	c++14

MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS} -fPIC -DPIC"

WRKSRC=		${WRKDIR}/caps-${PORTVERSION}

PLIST_FILES=	lib/ladspa/caps.so share/ladspa/rdf/caps.rdf

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-O2 -ffast-math -funroll-loops

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/caps.so ${STAGEDIR}${PREFIX}/lib/ladspa
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ladspa/rdf
	${INSTALL_DATA} ${WRKSRC}/caps.rdf ${STAGEDIR}${PREFIX}/share/ladspa/rdf

.include <bsd.port.mk>

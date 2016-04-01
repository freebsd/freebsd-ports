# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	caps-plugins
PORTVERSION=	0.4.5
CATEGORIES=	audio
MASTER_SITES=	http://quitte.de/dsp/
DISTNAME=	caps_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C* Audio Plugin Suite

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/caps-${PORTVERSION}

USES=		gmake
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS} -fPIC -DPIC"

PLIST_FILES=	lib/ladspa/caps.so share/ladspa/rdf/caps.rdf

OPTIMIZED_CFLAGS_CFLAGS=	-O2 -ffast-math -funroll-loops

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/caps.so ${STAGEDIR}${PREFIX}/lib/ladspa
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ladspa/rdf
	${INSTALL_DATA} ${WRKSRC}/caps.rdf ${STAGEDIR}${PREFIX}/share/ladspa/rdf

.include <bsd.port.mk>

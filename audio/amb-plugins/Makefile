# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amb-plugins
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://kokkinizita.linuxaudio.org/linuxaudio/downloads/
DISTNAME=	AMB-plugins-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fa-plugins.rdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ambisonics plugins, mainly to be used within Ardour

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		tar:bzip2 gmake
PLIST_FILES=	lib/ladspa/ambisonic0.so lib/ladspa/ambisonic1.so \
		lib/ladspa/ambisonic2.so lib/ladspa/ambisonic3.so \
		share/ladspa/rdf/fa-plugins.rdf

post-patch:
	@${REINPLACE_CMD} -e 's|[[:space:]]-O3||g ; \
		s|g++[[:space:]]|$$(CXX) |g' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa
.for i in 0 1 2 3
	${INSTALL_LIB} ${WRKSRC}/ambisonic${i}.so ${STAGEDIR}${PREFIX}/lib/ladspa
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ladspa/rdf
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/fa-plugins.rdf \
		${STAGEDIR}${PREFIX}/share/ladspa/rdf

.include <bsd.port.mk>

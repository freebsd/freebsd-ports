# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	stormbaancoureur
PORTVERSION=	2.1.6
CATEGORIES=	games
MASTER_SITES=	http://www.stolk.org/stormbaancoureur/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simulated obstacle course for automobiles

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib \
		${LOCALBASE}/lib/libode.a:devel/ode

USE_GL=		glut

MAKE_ENV=	DATADIR="${DATADIR}"

BUILD_WRKSRC=	${WRKSRC}/src-stormbaancoureur
INSTALL_WRKSRC=	${WRKSRC}/src-stormbaancoureur

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	ALSA DOCS
OPTIONS_DEFAULT=ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_MAKE_ENV=		ALSA_LIBS="-lasound"
ALSA_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-src-common-soundenginealsa.cxx \
			${FILESDIR}/extra-patch-src-common-soundenginealsa.h

post-patch:
	@${REINPLACE_CMD} -e 's|__DATADIR|"${DATADIR}"|' \
		${WRKSRC}/src-stormbaancoureur/main.cxx

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

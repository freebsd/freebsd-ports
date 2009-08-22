# New ports collection makefile for:	Hydrogen
# Date created:			23 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	hydrogen
PORTVERSION=	0.9.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Hydrogen/${PORTVERSION}%20-%20stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An advanced drum machine

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_QT_VER=	3
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_qmake="${LOCALBASE}/bin/qmake" \
		ac_libraries="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-alsa
MAKE_ENV=	QTDIR="${QT_PREFIX}" QMAKESPEC="freebsd-g++"

PLIST=		${WRKDIR}/pkg-plist

PLIST_FILES=	bin/hydrogen bin/hydrogenPlayer share/applications/hydrogen.desktop
PLIST_DIRS=	%%DATADIR%%

MAN1=		hydrogen.1
MANLANG=	"" ru.KOI8-R

OPTIONS=	JACK "JACK support" off \
		OSS "OSS support" on \
		PORTAUDIO "PortAudio support" off \
		LRDF "LRDF support" off \
		FLAC "FLAC support" on

.include <bsd.port.pre.mk>

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=--disable-jack-support
.endif

.if defined(WITHOUT_OSS)
CONFIGURE_ARGS+=--disable-oss-support
.endif

.if defined(WITH_PORTAUDIO)
CONFIGURE_ENV+=	PORTAUDIOPATH="${LOCALBASE}"
LIB_DEPENDS+=	portaudio.0:${PORTSDIR}/audio/portaudio
.endif

.if defined(WITH_LRDF)
LIB_DEPENDS+=	lrdf:${PORTSDIR}/textproc/liblrdf
.else
CONFIGURE_ARGS+=--disable-lrdf-support
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=--disable-flac-support
.endif

post-patch:
	@${MV} -f ${WRKSRC}/data/doc/man ${WRKSRC}
	@${RM} -f \
		${WRKSRC}/data/doc/*.docbook \
		${WRKSRC}/data/doc/updateManuals.sh \
		${WRKSRC}/data/i18n/*.ts \
		${WRKSRC}/data/i18n/updateTranslations.sh
	@${REINPLACE_CMD} -e 's|pa_unix_oss|lib|; s|pa_common|include|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' \
		${WRKSRC}/src/lib/Preferences.cpp \
		${WRKSRC}/src/lib/fx/LadspaFX.cpp \
		${WRKSRC}/src/tools/HydrogenPlayer.cpp
	@${REINPLACE_CMD} -e 's|/usr/share/hydrogen|${DATADIR}|' \
		${WRKSRC}/data/doc/img/Tutorial2.h2song
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/data/doc/manual_fr.html \
		${WRKSRC}/data/doc/manual_it.html

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} data ! -type d | ${SORT} | \
		${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} data -type d ! -empty | ${SORT} -r | \
		${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} '@dirrmtry share/applications' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydrogen ${WRKSRC}/hydrogenPlayer ${PREFIX}/bin
	cd ${WRKSRC} && \
	${FIND} data -type d ! -empty -exec ${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} data ! -type d -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/hydrogen.desktop ${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/man/C/hydrogen.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${MAN1PREFIX}/man/ru.KOI8-R/man1
	${INSTALL_MAN} ${WRKSRC}/man/ru/hydrogen.1 ${MAN1PREFIX}/man/ru.KOI8-R/man1

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	picard-plugins
PORTVERSION=	2.0.20210119
CATEGORIES=	audio python

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Plugins for Picard tagger

LICENSE=	GPLv2+ GPLv3+ MIT WTFPL
LICENSE_COMB=	multi

USES=		python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz
GH_TAGNAME=	3365403

PORTSCOUT=	limit:^2\.

NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/build
PLUGINSDIR=	${PYTHON_SITELIBDIR}/picard/plugins

OPTIONS_DEFINE=		ALBUM_COLUMN BPM MOODBAR
OPTIONS_GROUP=		REPLAYGAIN
OPTIONS_GROUP_REPLAYGAIN=	FLAC MP3 VORBIS WAVPACK
OPTIONS_SUB=		yes

ALBUM_COLUMN_DESC=	Adds album column to main window (can't be disabled)

BPM_DESC=		Beats per minute
BPM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aubio>=0.4.5:audio/py-aubio@${PY_FLAVOR}
BPM_SUB_FILES=		pkg-message.bmp
BPM_SUB_LIST=		GCC_VER=${GCC_DEFAULT:S/.//}
BPM_VARS=		PKGMESSAGE+=${.CURDIR}/pkg-message.bmp

MOODBAR_DESC=		Generate moodbar files
MOODBAR_RUN_DEPENDS=	moodbar:audio/moodbar

REPLAYGAIN_DESC=	ReplayGain audio normalization
FLAC_RUN_DEPENDS=	metaflac:audio/flac
MP3_RUN_DEPENDS=	mp3gain:audio/mp3gain
VORBIS_RUN_DEPENDS=	vorbisgain:audio/vorbisgain
WAVPACK_RUN_DEPENDS=	wvgain:audio/wavpack

do-build:
# Plugins that include a separate UI (those with an __init__.py) must
# be installed into their own subdirectories under PLUGINSDIR. Plugins
# written as a single .py file must be installed directly in PLUGINSDIR.
# We copy them into the correct hierarchy and compile them here.
	@${MKDIR} ${BUILD_WRKSRC}
	@(cd ${WRKSRC}/plugins; \
	   for dir in *; \
	   do \
	      if [ -f $${dir}/__init__.py ]; \
		 then ${CP} -R $${dir} ${BUILD_WRKSRC}; \
		 else ${CP} -R $${dir}/* ${BUILD_WRKSRC}; \
	      fi; \
	   done;)
	${FIND} ${BUILD_WRKSRC} -type f \( -name '.*' -o -name '*.bak' -o -name '*.orig' \) -exec ${RM} {} \;
	${PYTHON_CMD} -m compileall ${BUILD_WRKSRC}
	${PYTHON_CMD} -O -m compileall ${BUILD_WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PLUGINSDIR}
	(cd ${BUILD_WRKSRC}; ${COPYTREE_SHARE} . ${STAGEDIR}${PLUGINSDIR})

.include <bsd.port.mk>

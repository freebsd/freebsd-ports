# $FreeBSD$

PORTNAME=	picard-plugins
PORTVERSION=	2.0.20190101
CATEGORIES=	audio python

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Plugins for Picard tagger

LICENSE=	GPLv2+ GPLv3+ MIT WTFPL
LICENSE_COMB=	multi

USES=		python:3.5+
USE_PYTHON=	noflavors

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz
GH_TAGNAME=	9389d4d

PORTSCOUT=	limit:^2\.

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	GCC_VER=${GCC_DEFAULT:S/.//}

PLUGINSDIR=	${PYTHON_SITELIBDIR}/picard/plugins

OPTIONS_DEFINE=		BPM MOODBAR
OPTIONS_GROUP=		REPLAYGAIN
OPTIONS_GROUP_REPLAYGAIN=	FLAC MP3 VORBIS WAVPACK
OPTIONS_SUB=		yes

BPM_DESC=		Beats per minute
BPM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aubio>=0.4.5:audio/py-aubio@${PY_FLAVOR}

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
	@${MKDIR} ${WRKSRC}/build
	@(cd ${WRKSRC}/plugins; \
	   for dir in *; \
	   do \
	      if [ -f $${dir}/__init__.py ]; \
		 then ${CP} -R $${dir} ${WRKSRC}/build; \
		 else ${CP} -R $${dir}/* ${WRKSRC}/build; \
	      fi; \
	   done;)
	${PYTHON_CMD} -m compileall ${WRKSRC}/build
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/build

do-install:
	@${MKDIR} ${STAGEDIR}${PLUGINSDIR}
	(cd ${WRKSRC}/build; ${COPYTREE_SHARE} . ${STAGEDIR}${PLUGINSDIR})

post-install-BPM-off:
	@${RM} -r ${STAGEDIR}${PLUGINSDIR}/bpm

.include <bsd.port.mk>

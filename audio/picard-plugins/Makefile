# $FreeBSD$

PORTNAME=	picard-plugins
PORTVERSION=	1.0.20180211
CATEGORIES=	audio python

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Plugins for Picard tagger

LICENSE=	GPLv2+ GPLv3+ MIT WTFPL
LICENSE_COMB=	multi

USES=		python:2.7

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz
GH_TAGNAME=	7d0cf37

PORTSCOUT=	limit:^1\.

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
	${PYTHON_CMD} -m compileall ${WRKSRC}/plugins
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/plugins

do-install:
# Plugins that include a separate UI (those with an __init__.py) must
# be installed into their own subdirectories under PLUGINSDIR. Plugins
# written as a single .py file must be installed directly in PLUGINSDIR.
	@${MKDIR} ${STAGEDIR}${PLUGINSDIR}
	@(cd ${WRKSRC}/plugins; \
	   for dir in *; \
	   do \
	      if [ -f $${dir}/__init__.py ]; \
	         then ${COPYTREE_SHARE} $${dir} ${STAGEDIR}${PLUGINSDIR} "! -name *\.orig"; \
	         else ${INSTALL_DATA} $${dir}/* ${STAGEDIR}${PLUGINSDIR}; \
	      fi; \
	   done;)

post-install-BPM-off:
	@${RM} -r ${STAGEDIR}${PLUGINSDIR}/bpm

.include <bsd.port.mk>

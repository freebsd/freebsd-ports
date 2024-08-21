PORTNAME=	picard-plugins
PORTVERSION=	2.0.20240712
CATEGORIES=	audio python

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Plugins for Picard tagger
WWW=		https://picard.musicbrainz.org/plugins/

LICENSE=	GPLv2+ GPLv3+ MIT WTFPL
LICENSE_COMB=	multi

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz
GH_TAGNAME=	1fd3cfe

PORTSCOUT=	limit:^2\.

NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/build
PLUGINSDIR=	${PYTHON_SITELIBDIR}/picard/plugins

OPTIONS_DEFINE=		BPM DOCS MOODBAR REPLAYGAIN2
OPTIONS_SUB=		yes

BPM_DESC=		Beats per minute
BPM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aubio>=0.4.5:audio/py-aubio@${PY_FLAVOR}
BPM_SUB_FILES=		pkg-message.bmp
BPM_SUB_LIST=		GCC_VER=${GCC_DEFAULT:S/.//}
BPM_VARS=		PKGMESSAGE+=${.CURDIR}/pkg-message.bmp

MOODBAR_DESC=		Generate moodbar files
MOODBAR_RUN_DEPENDS=	moodbar:audio/moodbar

REPLAYGAIN2_DESC=		ReplayGain 2.0 audio normalization
REPLAYGAIN2_RUN_DEPENDS=	rsgain:audio/rsgain

post-patch:
	${RM} -rf ${WRKSRC}/plugins/haikuattrs

do-build:
# Plugins that include a separate UI (those with an __init__.py) must
# be installed into their own subdirectories under PLUGINSDIR. Plugins
# written as a single .py file must be installed directly in PLUGINSDIR.
# We copy them into the correct hierarchy and compile them here.
	@${MKDIR} ${BUILD_WRKSRC}/plugins
	@(cd ${WRKSRC}/plugins; \
	   for dir in *; \
	   do \
	      if [ -f $${dir}/[Rr][Ee][Aa][Dd][Mm][Ee]* ]; \
		 then ${MKDIR} ${BUILD_WRKSRC}/doc/$${dir}; \
		      ${MV} $${dir}/[Rr][Ee][Aa][Dd][Mm][Ee]* ${BUILD_WRKSRC}/doc/$${dir}; \
	      fi; \
	      if [ -d $${dir}/docs ]; \
		 then ${MKDIR} ${BUILD_WRKSRC}/doc/$${dir}; \
		      ${MV} $${dir}/docs/* ${BUILD_WRKSRC}/doc/$${dir}; \
		      ${RM} -r $${dir}/docs; \
	      fi; \
	      if [ -f $${dir}/__init__.py ]; \
		 then ${CP} -R $${dir} ${BUILD_WRKSRC}/plugins; \
		 else ${CP} -R $${dir}/* ${BUILD_WRKSRC}/plugins; \
	      fi; \
	   done;)
	${FIND} ${BUILD_WRKSRC} -type f \( -name '.*' -o -name '*.bak' -o -name '*.orig' \) -exec ${RM} {} \;
	${PYTHON_CMD} -m compileall ${BUILD_WRKSRC}/plugins
	${PYTHON_CMD} -O -m compileall ${BUILD_WRKSRC}/plugins

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${BUILD_WRKSRC}/doc; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${PLUGINSDIR}
	(cd ${BUILD_WRKSRC}/plugins; ${COPYTREE_SHARE} . ${STAGEDIR}${PLUGINSDIR})

.include <bsd.port.mk>

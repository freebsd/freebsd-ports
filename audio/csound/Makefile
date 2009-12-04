# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $Carpetsmoker: ports/audio/csound/Makefile,v 1.5 2007/11/18 11:10:22 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	5.11.1
PORTREVISION=	1
CATEGORIES=	audio lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}5.11/:src \
		SF/${PORTNAME}/${PORTNAME}5/${PORTNAME}5.10/:manual
# Developer does not include a newer version of the manual.
MASTER_SITE_SUBDIR=	${PORTNAME:S/$/:src/}
DISTNAME=	${PORTNAME:S/c/C/}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src
DIST_SUBDIR=	csound

MAINTAINER=	chris@officialunix.com
COMMENT=	Sound synthesizer

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads
BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13

WRKSRC=		${WRKDIR}/${DISTNAME}/
USE_PYTHON=	2.6+
USE_SCONS=	yes
SCONS_ARGS+=	prefix=${PREFIX} CC=${CC} CXX=${CXX} \
		usePortAudio=0 usePortMIDI=0 useALSA=0 \
		useJack=0 useFLTK=1 buildCsoundAC=0 buildCsoundVST=0 \
		buildCsound5GUI=1 buildRelease=1 install=1 \
		useCoreAudio=1 buildWinsound=1 buildInterfaces=1 \
		buildVirtual=1 buildCSEditor=1 buildDSSI=0 \
		useGettext=1 dynamicCsoundLibrary=1 useDouble=1
USE_GETTEXT=	yes
SUB_FILES=	custom.py pkg-message
SUB_LIST+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
DISTFILES+=	Csound5.10_manual_html.zip:manual
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Fails to link
.endif

post-patch: apply-slist
	@${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/check-fltk-threads.sh
	@${MV} ${WRKDIR}/custom.py ${WRKSRC}
	@${REINPLACE_CMD} -e "s|'unsupported'|'linux'|; \
		s|ENV = {'PATH' : os.environ\['PATH'\]}|ENV = os.environ|; \
		s|'dl'|''|; \
		s|'asound'|''|;" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} 's|linux/if.h|net/if.h|' ${WRKSRC}/OOps/remote.c
	@${REINPLACE_CMD} 's|malloc.h|stdlib.h|' \
		${WRKSRC}/frontends/CsoundAC/Counterpoint.hpp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${ECHO_MSG} " Installing the manual."
	cd ${WRKDIR}/html && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${ECHO_MSG} " Done."
.endif
	@${ECHO_MSG} " Moving ${PREFIX}/bin/mixer to ${PREFIX}/bin/csmixer"
	@${ECHO_MSG} " This is to prevent conflicts with /usr/bin/mixer"
	${MV} ${PREFIX}/bin/mixer ${PREFIX}/bin/csmixer
	@${ECHO_MSG} " Done."
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $Carpetsmoker: ports/audio/csound/Makefile,v 1.5 2007/11/18 11:10:22 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	5.07
CATEGORIES=	audio lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.carpetsmoker.net/distfiles/:manual \
		http://www.xs4all.nl/~tournoij/distfiles/:manual \
		http://www.rwxrwxrwx.net/distfiles/:manual
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/c/C/}${PORTVERSION}.0
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	csound

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Sound synthesizer

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads
BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13

WRKSRC=		${WRKDIR}/csound5
USE_PYTHON=	2.4+
USE_SCONS=	yes
SCONS_ARGS+=	prefix=${PREFIX} CC=${CC} CXX=${CXX} \
		usePortAudio=0 usePortMIDI=0 useALSA=0 \
		useJack=0 useFLTK=1 buildCsoundAC=0 buildCsoundVST=0 \
		buildCsound5GUI=1 buildRelease=1 install=1 \
		useCoreAudio=1 buildWinsound=1 buildInterfaces=1 \
		buildVirtual=1 buildCSEditor=1 buildDSSI=0
SUB_FILES=	custom.py pkg-message
SUB_LIST+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
USE_LDCONFIG=	${PREFIX}/lib/csound/plugins

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}-manual.tar.gz:manual
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Fails to link
.endif

post-patch: apply-slist
	@${SETENV} FLTKBASE=${FLTKBASE} ${SH} ${SCRIPTDIR}/check-fltk-threads.sh
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
	${INSTALL_DATA} ${WRKDIR}/csound-manual/tutorial_${PORTVERSION}.pdf ${DOCSDIR}
	${CP} -r ${WRKDIR}/csound-manual/html ${DOCSDIR}
.endif
	${MV} ${PREFIX}/bin/mixer ${PREFIX}/bin/csmixer
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $Carpetsmoker: ports/audio/csound/Makefile,v 1.3 2007/07/22 00:52:59 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	5.06
CATEGORIES=	audio lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.carpetsmoker.net/distfiles/:manual \
		http://www.xs4all.nl/~tournoij/distfiles/:manual \
		http://www.rwxrwxrwx.net/distfiles/:manual
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/c/C/}${PORTVERSION}.0
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	csound

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Sound synthesizer

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk-threads \
		portaudio.2:${PORTSDIR}/audio/portaudio2
BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13

WRKSRC=		${WRKDIR}/${DISTNAME:S/_src/.0/}
USE_PYTHON=	2.4+
USE_SCONS=	yes
SCONS_ARGS+=	prefix=${PREFIX} CC=${CC} CXX=${CXX} \
		buildRelease=1 install=1 buildCsound5GUI=1 \
		buildWinsound=1 buildVirtual=1 buildCSEditor=1 Word64=1
SUB_FILES=	custom.py \
		pkg-message
SUB_LIST+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}-manual.tar.gz:manual
.endif

FLTKBASE?=	${LOCALBASE}
post-patch: apply-slist
	@${SETENV} FLTKBASE=${FLTKBASE} ${SH} ${SCRIPTDIR}/check-fltk-threads.sh
	@${MV} ${WRKDIR}/custom.py ${WRKSRC}
	@${REINPLACE_CMD} -e "s|'unsupported'|'linux'|; \
		s|ENV = {'PATH' : os.environ\['PATH'\]}|ENV = os.environ|; \
		s|'dl'|''| ; s|lib64|lib|g" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} 's|linux/if.h|net/if.h|' ${WRKSRC}/OOps/remote.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/csound-manual/tutorial_${PORTVERSION}.pdf ${DOCSDIR}
	${CP} -r ${WRKDIR}/csound-manual/html ${DOCSDIR}
.endif
	${MV} ${PREFIX}/bin/mixer ${PREFIX}/bin/cs_mixer
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Fails to link
.endif

.include <bsd.port.post.mk>

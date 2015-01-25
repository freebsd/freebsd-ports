# Created by: Pontus Stenetorp <ninjin@kth.se>
# $FreeBSD$

PORTNAME=	fastaudio
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://freenet.mcnabhosting.com/python/pyPortAudio/:site1 \
		http://www.portaudio.com/archives/:site2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fastaudio
DISTFILES=	fastaudio.tar.gz:site1 portaudio_v18_1.zip:site2
DIST_SUBDIR=	python

MAINTAINER=	ninjin@kth.se
COMMENT=	Python bindings for the PortAudio multi-platform audio library

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	libportaudio.so.0:${PORTSDIR}/audio/portaudio \
		libsndfile.so:${PORTSDIR}/audio/libsndfile

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/fastaudio.so
EXAMPLESDIR=	${LOCALBASE}/share/examples/py-${PORTNAME}

USES=		python zip:infozip
USE_PYTHON=	distutils

FASTA_SRCFILE=	fastaudio.tar.gz
PORTA_SRCFILE=	portaudio_v18_1.zip
PORTASRC_DIR=	${WRKDIR}/portaudio_v18_1/

.if !defined(WITHOUT_EXAMPLES)
PLIST_FILES+=	share/examples/py-${PORTNAME}/demo.py
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/${FASTA_SRCFILE} -C ${WRKDIR}
	@${UNZIP_CMD} -q -d ${WRKDIR}/ \
		${DISTDIR}/${DIST_SUBDIR}/${PORTA_SRCFILE}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py ${WRKSRC}/mysndfile.h ${WRKSRC}/fastaudio.pyx
# Borrowed from the portaudio port, fixes obsolete path
	@${REINPLACE_CMD} -e 's|machine\/soundcard.h|sys\/soundcard.h|' \
		${PORTASRC_DIR}/pa_unix_oss/pa_unix_oss.c

post-install:
.if !defined(WITHOUT_EXAMPLES)
	( ${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/demo.py ${STAGEDIR}${EXAMPLESDIR}/ )
.endif

.include <bsd.port.mk>
